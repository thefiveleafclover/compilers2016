// $Id: or_node.h,v 1.1 2016/03/15 23:17:42 ist178929 Exp $ -*- c++ -*-
#ifndef __ZU_AST_EXPRESSION_OR_H__
#define __ZU_AST_EXPRESSION_OR_H__

#include <cdk/ast/binary_expression_node.h>

namespace zu {

  /**
   * Class for describing the sum ('+') operator
   */
  class or_node: public cdk::binary_expression_node {
  public:
    /**
     * @param lineno source code line number for this node
     * @param left first operor
     * @param right second operor
     */
    inline or_node(int lineno, expression_node *left, expression_node *right) :
        cdk::binary_expression_node(lineno, left, right) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_or_node(this, level);
    }

  };

} // zu

#endif
