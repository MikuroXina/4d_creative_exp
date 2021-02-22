#include "button.hpp"

SoftwareButton::SoftwareButton(Text text) : text{text} {}

void SoftwareButton::write(Frame &tex) const {
  tex.draw_border(text.region());
  text.write(tex);
}
