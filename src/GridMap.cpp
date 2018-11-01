
# include <pcl>

template <typename T>
class GridMap<T>{

private:
    unsigned int length; // L
    unsigned int width; // W
    unsigned int cellSize; // c_size
    std::vector<<std::vector<T> > map;

public:
    GridpMap();
    ~GridMap();
    void setPoint(int x, int y);
    bool fits(pcl::PointXYZ &point){
        return (point.x + length / 2) / cellSize) < (length / cellSize);
    }


};
