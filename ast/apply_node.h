 
// $Id: for_node.h,v 1.4 2016/05/19 14:03:03 ist178929 Exp $ -*- c++ -*-
#ifndef __APPLY_H__
#define __APPLY_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing while-cycle nodes.
   */
  class apply_node: public cdk::basic_node {
    cdk::sequence_node *_functionName;
    cdk::expression_node *_vectorIdentifier;
    cdk::expression_node *_lowIndex;
    cdk::basic_node *_highIndex;

  public:
    inline apply_node(int lineno, cdk::sequence_node *functionName, cdk::expression_node *vectorIdentifier, cdk::expression_node *lowIndex, cdk::basic_node *highIndex) :
        basic_node(lineno), _functionName(functionName), _vectorIdentifier(vectorIdentifier), _lowIndex(lowIndex), _highIndex(highIndex) {
    }

  public:
    inline cdk::sequence_node *functionName() {
      return _functionName;
    }

    inline cdk::expression_node *vectorIdentifier() {
      return _vectorIdentifier;
    }
    
    inline cdk::expression_node *lowIndex() {
      return _lowIndex;
    }
    
    inline cdk::basic_node *highIndex() {
      return _highIndex;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_apply_node(this, level);
    }

  };

} // zu

#endif
 