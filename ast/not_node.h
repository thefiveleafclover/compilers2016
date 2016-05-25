// $Id: not_node.h,v 1.1 2016/03/15 23:17:42 ist178929 Exp $ -*- c++ -*-
#ifndef __ZU_AST_EXPRESSION_NOT_H__
#define __ZU_AST_EXPRESSION_NOT_H__

#include <cdk/ast/unary_expression_node.h>

namespace zu {

  /**
   * Class for describing the negation operator
   */
  class not_node: public cdk::unary_expression_node {
  public:
    inline not_node(int lineno, expression_node *arg) :
        cdk::unary_expression_node(lineno, arg) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_not_node(this, level);
    }

  };

} // zu

#endif
