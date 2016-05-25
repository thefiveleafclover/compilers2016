// $Id: function_node.h,v 1.1 2016/03/15 23:17:42 ist178929 Exp $ -*- c++ -*-
#ifndef __ZU_FUNCTIONNODE_H__
#define __ZU_FUNCTIONNODE_H__

#include <cdk/ast/basic_node.h>

namespace zu {

  /**
   * Class for describing program nodes.
   */
  class function_node: public cdk::basic_node {
    cdk::basic_node *_statements;

  public:
    inline function_node(int lineno, cdk::basic_node *statements) :
        cdk::basic_node(lineno), _statements(statements) {
    }

  public:
    inline cdk::basic_node *statements() {
      return _statements;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_node(this, level);
    }

  };

} // zu

#endif
