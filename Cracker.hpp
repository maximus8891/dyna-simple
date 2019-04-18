#ifndef CRACKER_H

#define CRACKER_H

#include <vector>
#include "Character.hpp"

class Cracker : public Character
{
  static const int timeout = 2;
  static const int blastout = 2;
  unsigned char state = TIMEOUT;
  int timer = 0;
  int blast = 0;
  std::vector<XY> blast_cells;

  public:
    Cracker(XY starting_position);

    void tick();

    bool blast_collides_with(const Character* p) const;

    bool is_gone();

    void draw(DrawSquareAt* context) const;

    void handle_timeout();
    void handle_explode();
    void update_blast();
    bool is_valid_tile(OBJECT tile);
};

#endif /* end of include guard: CRACKER_H */
