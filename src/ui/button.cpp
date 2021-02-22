#include "button.hpp"

SoftwareButton::SoftwareButton(KatakanaString text) : text{text} {}

void SoftwareButton::write(Frame &tex) const {
  tex.draw_border(text.region());
  text.write(tex);
}
