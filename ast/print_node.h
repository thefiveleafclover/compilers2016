// $Id: print_node.h,v 1.3 2016/05/20 12:44:37 ist178929 Exp $ -*- c++ -*-
#ifndef __ZU_PRINTNODE_H__
#define __ZU_PRINTNODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing print nodes.
   */
  class print_node: public cdk::basic_node {
    cdk::expression_node *_argument;
    bool _nl;

  public:
    inline print_node(int lineno, cdk::expression_node *argument, bool nl) :
        cdk::basic_node(lineno), _argument(argument), _nl(nl) {
    }

  public:
    inline cdk::expression_node *argument() {
      return _argument;
    }
    
    inline bool nl(){
        return _nl;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_print_node(this, level);
    }

  };

} // zu

#endif
