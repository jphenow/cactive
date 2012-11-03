// Include the Ruby headers and goodies
#include "ruby.h"

// Prototype for our method 'test1' - methods are prefixed by 'method_' here
//VALUE method_from(VALUE self, VALUE position);
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

static VALUE
rb_str_aref(VALUE str, VALUE indx)
{
    long idx;

    if (FIXNUM_P(indx)) {
	idx = FIX2LONG(indx);

      num_index:
	str = rb_str_substr(str, idx, 1);
	if (!NIL_P(str) && RSTRING_LEN(str) == 0) return Qnil;
	return str;
    }

    if (SPECIAL_CONST_P(indx)) goto generic;
    switch (BUILTIN_TYPE(indx)) {
      case T_REGEXP:
	return rb_str_subpat(str, indx, INT2FIX(0));

      case T_STRING:
	if (rb_str_index(str, indx, 0) != -1)
	    return rb_str_dup(indx);
	return Qnil;

      generic:
      default:
	/* check if indx is Range */
	{
	    long beg, len;
	    VALUE tmp;

	    len = str_strlen(str, STR_ENC_GET(str));
	    switch (rb_range_beg_len(indx, &beg, &len, len, 0)) {
	      case Qfalse:
		break;
	      case Qnil:
		return Qnil;
	      default:
		tmp = rb_str_substr(str, beg, len);
		return tmp;
	    }
	}
	idx = NUM2LONG(indx);
	goto num_index;
    }

    UNREACHABLE;
}

VALUE method_from(VALUE self, VALUE position) {
  end = RSTRING_LEN(self);
  start = FIX2INT(position);
  length = end - start;
  VALUE new_string[length];
  for(i = start; i < end + 1; i++)
  {
    new_string[i-start] = rb_str_aref(i, self);
  }
  newstr = rb_str_new(0, length);
  for(i = 0; i < sizeof(new_string) + 1; i++)
  {
    newstr = rb_string_concat(newstr, new_string[i]);
  }
  return newstr;
}

VALUE method_to(VALUE self, VALUE position) {
  VALUE positions[2] = { INT2FIX(0), position };
  return rb_str_aref(2, positions, self);
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
