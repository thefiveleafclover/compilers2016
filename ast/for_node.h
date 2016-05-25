// $Id: for_node.h,v 1.4 2016/05/19 14:03:03 ist178929 Exp $ -*- c++ -*-
#ifndef __FOR_H__
#define __FOR_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing while-cycle nodes.
   */
  class for_node: public cdk::basic_node {
    cdk::sequence_node *_init;
    cdk::expression_node *_condition;
    cdk::expression_node *_incr;
    cdk::basic_node *_block;

  public:
    inline for_node(int lineno, cdk::sequence_node *init, cdk::expression_node *condition, cdk::expression_node *incr, cdk::basic_node *block) :
        basic_node(lineno), _init(init), _condition(condition), _incr(incr), _block(block) {
    }

  public:
    inline cdk::sequence_node *init() {
      return _init;
    }

    inline cdk::expression_node *condition() {
      return _condition;
    }
    
    inline cdk::expression_node *incr() {
      return _incr;
    }
    
    inline cdk::basic_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_for_node(this, level);
    }

  };

} // zu

#endif
 
