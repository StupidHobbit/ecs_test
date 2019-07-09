#ifndef TETRIS_CONTROLS_H
#define TETRIS_CONTROLS_H

struct Controls {
    bool w, a, s, d;
public:
    Controls(bool w,
             bool a,
             bool s,
             bool d
    ) : w(w), a(a), s(s), d(d) {}
    Controls() : Controls(0, 0, 0, 0) {}
};

#endif //TETRIS_CONTROLS_H
