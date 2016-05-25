#ifndef __ZU_AST_EXPRESSION_NOT_H__
#define __ZU_AST_POINTER_H__

#include <cdk/ast/unary_expression_node.h>

namespace zu {

  /**
   * Class for describing the negation operator
   */
  class memalloc_node: public cdk::unary_expression_node {
  public:
    inline memalloc_node(int lineno, expression_node *arg) :
        cdk::unary_expression_node(lineno, arg) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_memalloc_node(this, level);
    }

  };

} // zu

#endif