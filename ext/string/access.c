// Include the Ruby headers and goodies
#include "ruby.h"

VALUE method_at(VALUE self, VALUE position);
VALUE method_from(VALUE self, VALUE position);
VALUE method_to(VALUE self, VALUE position);
VALUE method_first(VALUE self);
VALUE method_last(VALUE self);

// The initialization method for this module
void Init_string() {
  rb_define_method(rb_cString, "at", method_at, 1);
  rb_define_method(rb_cString, "from", method_from, 1);
  rb_define_method(rb_cString, "to", method_to, 1);
  rb_define_method(rb_cString, "first", method_first, 0);
  rb_define_method(rb_cString, "last", method_last, 0);
}

VALUE method_at(VALUE self, VALUE position) {
  return rb_str_substr(self, FIX2INT(position), 1);
}

VALUE method_from(VALUE self, VALUE position) {
  return rb_str_substr(self, FIX2INT(position), RSTRING_LEN(self) - 1);
}

VALUE method_to(VALUE self, VALUE position) {
  return rb_str_substr(self, 0, (FIX2INT(position) + 1));
}

VALUE method_first(VALUE self) {
  return rb_str_substr(self, 0, 1);
}

VALUE method_last(VALUE self) {
  return rb_str_substr(self, RSTRING_LEN(self) - 1, 1);
}
