// Include the Ruby headers and goodies
#include "ruby.h"

/*VALUE method_at(VALUE self, VALUE position);*/
VALUE method_from(VALUE self, VALUE position);
VALUE method_to(VALUE self, VALUE position);
/*VALUE method_first(VALUE self);*/
/*VALUE method_last(VALUE self);*/

// The initialization method for this module
void Init_string() {
  /*rb_define_method(rb_cString, "at", method_at, 1);*/
  rb_define_method(rb_cString, "from", method_from, 1);
  rb_define_method(rb_cString, "to", method_to, 1);
  /*rb_define_method(rb_cString, "first", method_frst, 0);*/
  /*rb_define_method(rb_cString, "last", method_last, 0);*/
}

VALUE method_from(VALUE self, VALUE position) {
  return rb_str_substr(self, FIX2INT(position), RSTRING_LEN(self) - 1);
}

VALUE method_to(VALUE self, VALUE position) {
  return rb_str_substr(self, 0, (FIX2INT(position) + 1));
}

/*VALUE method_second(VALUE self) {*/
  /*int idx = 1;*/
  /*return rb_ary_entry(self, idx);*/
/*}*/

/*VALUE method_third(VALUE self) {*/
  /*int idx = 2;*/
  /*return rb_ary_entry(self, idx);*/
/*}*/

/*VALUE method_fourth(VALUE self) {*/
  /*int idx = 3;*/
  /*return rb_ary_entry(self, idx);*/
/*}*/

/*VALUE method_fifth(VALUE self) {*/
  /*int idx = 4;*/
  /*return rb_ary_entry(self, idx);*/
/*}*/

/*VALUE method_forty_two(VALUE self) {*/
  /*int idx = 41;*/
  /*return rb_ary_entry(self, idx);*/
/*}*/
