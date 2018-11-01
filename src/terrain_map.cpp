/*
Implementation of http://journals.sagepub.com/doi/full/10.1177/1729881417751530
by Xiangrui Meng, Zhiqiang Cao, Shuang Liang, Lei Pang,
Shuo Wang, and Chao Zhou
*/

#include <Eigen/Eigenvalues>

#include <pcl>


class TravMap()
{

    TravMap(**args){
        return 0;
    }

    
    }

  int roughness(PointCloud<XYZ> Qf){
    // calculate roughness
    int xm = 0, ym = 0, zm = 0;

    CloudSize = Qf.size();

    for(int i = 0; i < CloudSize, i++) {
      xm += Qf[i].x;
      ym += Qf[i].y;
      zm += Qf[i].z;
    }
    xm /= CloudSize;
    ym /= CloudSize;
    zm /= CloudSize;

    int a[6] = {0, 0, 0, 0, 0, 0};

    for(int j = 0; j < CloudSize; j++) {
      int x = Qf[j].x;
      int y = Qf[j].y;
      int z = Qf[j].z;
      int t1 = x - xm;
      int t2 = y - ym;
      int t3 = z - zm;
      a[1] += t1 * t1;
      a[2] += t1 * t2;
      a[3] += t1 * t3;
      a[4] += t2 * t2;
      a[5] += t2 * t3;
      a[6] += t3 * t3;
    }

    // TODO Convert to matrix
    EigenSolver<MatrixXd> es();
    v = eigenvectors(a);
    lambda = inverse(V) dot S dot V;
    lambda_0 = min(lambda);
    lambda_2 = max(lambda);
    lambda_1 = sum(lambda) - lambda_0 - lambda_2;

    if(lambda_0 != 0 && lambda_1/lambda_0 >= T_ratio &&
    lambda_1 >= T_L && lamvda_0 <= T_s) {
      return 0;
    }
    else {
      return 1;
    }

  }


}
