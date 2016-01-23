#pragma once

namespace console{

namespace ui{

class focusable{
public:
    focusable(bool state = false);

    void focus();
    void unfocus();
    bool focused() const;
protected:
    virtual void set_focus_state(bool);
private:
    bool focus_state;
};

}

}