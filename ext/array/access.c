// Include the Ruby headers and goodies
#include "ruby.h"

VALUE method_from(VALUE self, VALUE position);
VALUE method_to(VALUE self, VALUE position);
VALUE method_second(VALUE self);
VALUE method_third(VALUE self);
VALUE method_fourth(VALUE self);
VALUE method_fifth(VALUE self);
VALUE method_forty_two(VALUE self);

// The initialization method for this module
void Init_array() {
  rb_define_method(rb_cArray, "from", method_from, 1);
  rb_define_method(rb_cArray, "to", method_to, 1);
  rb_define_method(rb_cArray, "second", method_second, 0);
  rb_define_method(rb_cArray, "third", method_third, 0);
  rb_define_method(rb_cArray, "fourth", method_fourth, 0);
  rb_define_method(rb_cArray, "fifth", method_fifth, 0);
  rb_define_method(rb_cArray, "forty_two", method_forty_two, 0);
}

// TODO Yes re-impleneted from array.c .... would love a better way plx thx
VALUE rb_ary_aref(int argc, VALUE *argv, VALUE ary) {
  VALUE arg;
  long beg, len;

  if (argc == 2) {
    beg = NUM2LONG(argv[0]);
    len = NUM2LONG(argv[1]);
    if (beg < 0) {
      beg += RARRAY_LEN(ary);
    }
    return rb_ary_subseq(ary, beg, len);
  }
  if (argc != 1) {
    rb_scan_args(argc, argv, "11", 0, 0);
  }
  arg = argv[0];
  /* special case - speeding up */
  if (FIXNUM_P(arg)) {
    return rb_ary_entry(ary, FIX2LONG(arg));
  }
  /* check if idx is Range */
  switch (rb_range_beg_len(arg, &beg, &len, RARRAY_LEN(ary), 0)) {
    case Qfalse:
      break;
    case Qnil:
      return Qnil;
    default:
      return rb_ary_subseq(ary, beg, len);
  }
  return rb_ary_entry(ary, NUM2LONG(arg));
}

VALUE method_from(VALUE self, VALUE position) {
  VALUE positions[2] = { position, INT2FIX(RARRAY_LEN(self)) };
  return rb_ary_aref(2, positions, self);
}

VALUE method_to(VALUE self, VALUE position) {
  VALUE positions[2] = { INT2FIX(0), position };
  return rb_ary_aref(2, positions, self);
}

VALUE method_second(VALUE self) {
  int idx = 1;
  return rb_ary_entry(self, idx);
}

VALUE method_third(VALUE self) {
  int idx = 2;
  return rb_ary_entry(self, idx);
}

VALUE method_fourth(VALUE self) {
  int idx = 3;
  return rb_ary_entry(self, idx);
}

VALUE method_fifth(VALUE self) {
  int idx = 4;
  return rb_ary_entry(self, idx);
}

VALUE method_forty_two(VALUE self) {
  int idx = 41;
  return rb_ary_entry(self, idx);
}
