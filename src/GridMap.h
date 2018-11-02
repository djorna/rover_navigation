


template <typename T>
class GridMap<T>{

private:
    unsigned length; // L
    unsigned width; // W
    unsigned cellSize; // c_size
    std::tuple<float x, float y> origin;

public:
  GridpMap();
  ~GridMap();
  void setPoint(int x, int y);

  void addPointToGridMap(const pcl::PointXYZ &point)

  void pointToGrid(pcl::PointXYZ point, GridMap &map){

      int lengh = map.getLength();
      unsigned cellSize = map.getCellSize();

      if((point.x + length/2) / C_SIZE) < length / C_SIZE){
          // map point to grid

      }
      else{

      }

};
