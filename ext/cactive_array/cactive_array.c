// Include the Ruby headers and goodies
#include "ruby.h"

// Defining a space for information and references about the module to be stored internally
//VALUE CactiveArray = Qnil;

// Prototype for the initialization method - Ruby calls this, not you
//void Init_cactive_array();

// Prototype for our method 'test1' - methods are prefixed by 'method_' here
//VALUE method_from(VALUE self, VALUE position);
VALUE method_from(VALUE self, VALUE position);
VALUE method_to(VALUE self, VALUE position);

// The initialization method for this module
void Init_cactive_array() {
  //CactiveArray = rb_define_class("Array", rb_cObject);
  rb_define_method(rb_cArray, "from", method_from, 1);
  rb_define_method(rb_cArray, "to", method_to, 1);
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
