/*
 * Software License Agreement (BSD License)
 *
 *  Point Cloud Library (PCL) - www.pointclouds.org
 *  Copyright (c) 2012-, Open Perception, Inc.
 *
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the copyright holder(s) nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

 // Original source:
 // https://github.com/PointCloudLibrary/pcl/blob/master/tools/xyz2pcd.cpp

#include <pcl/io/pcd_io.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>

using namespace std;
using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;

void printHelp (int, char **argv)
{
  print_error ("Syntax is: %s input.xyz output.pcd\n", argv[0]);
}

bool loadCloud (const string &filename, PointCloud<PointXYZ> &cloud)
{
  ifstream fs;
  fs.open (filename.c_str (), ios::binary);
  if (!fs.is_open () || fs.fail ())
  {
    PCL_ERROR ("Could not open file '%s'! Error : %s\n", filename.c_str (), strerror (errno));
    fs.close ();
    return (false);
  }

  string line;
  vector<string> st;

  while (!fs.eof ())
  {
    getline (fs, line);
    // Ignore empty lines
    if (line == "")
      continue;

    // Tokenize the line
    boost::trim (line);
    boost::split (st, line, boost::is_any_of ("\t\r "), boost::token_compress_on);

    if (st.size () != 3)
      continue;

    cloud.push_back (PointXYZ (float (atof (st[0].c_str ())), float (atof (st[1].c_str ())), float (atof (st[2].c_str ()))));
  }
  fs.close ();

  cloud.width = uint32_t (cloud.size ()); cloud.height = 1; cloud.is_dense = true;
  return (true);
}

// For iterating through files

#define BOOST_FILESYSTEM_VERSION 3
#define BOOST_FILESYSTEM_NO_DEPRECATED 
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = ::boost::filesystem;

// return the filenames of all files that have the specified extension
// in the specified directory and all subdirectories
void get_all(const fs::path& root, const string& ext, vector<fs::path>& ret)
{
    if(!fs::exists(root) || !fs::is_directory(root)) return;

    std::cout << "trying...\n";

    fs::recursive_directory_iterator it(root);
    fs::recursive_directory_iterator endit;

    while(it != endit)
    {
        if(fs::is_regular_file(*it) && it->path().extension() == ext) ret.push_back(it->path());
        ++it;

    }

}

int main (int argc, char** argv)
{
  print_info ("Convert a simple XYZ file to PCD format. For more information, use: %s -h\n", argv[0]);

  std::string root(argc <= 1 ? "." : argv[1]); // get root dir or use current dir
  vector<fs::path> paths;
  get_all(root, ".xyz", paths);

  if (paths.size() == 0) {
    std::cout << "No xyz files found in directory\n";
  }
  else {
    std::cout << "Converting " << paths.size() << " xyz files to pcd.\n";
  }

  PCDWriter w;

  for (auto it = paths.begin(); it != paths.end(); ++it) {
    PointCloud<PointXYZ> cloud;
    loadCloud(it->generic_string(), cloud);
    fs::path newFile = it->replace_extension(".pcd");
    if (fs::exists(newFile)) {
      cout << newFile << " already exits.\n";
    }
    else {
      w.writeBinaryCompressed(newFile.generic_string(), cloud);
      cout << "\nSuccessfully converted "<< *it << " to pcd and saved as " << newFile;
    }
  }

  cout << "\nFinished.\n";
}

