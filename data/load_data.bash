wget "ftp://asrl3.utias.utoronto.ca/3dmap_dataset/p2at_met/p2at_met.zip"
unzip p2at_met.zip 
# Build xyz => pcd conversion program
cmake ./convert/
make ./convert/
# Convert all file in folder recursively
./convert/xyz2pcd .