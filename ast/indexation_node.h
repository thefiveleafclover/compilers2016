#ifndef __ZU_AST_EXPRESSION_INDEXATION_H__
#define __ZU_AST_EXPRESSION_INDEXATION_H__

#include <cdk/ast/binary_expression_node.h>
#include <ast/lvalue_node.h>

namespace zu {

  class indexation_node: public zu::lvalue_node {
  public:
    /**
     * @param lineno source code line number for this node
     * @param left first operand
     * @param right second operand
     */
    inline indexation_node(int lineno, cdk::expression_node *left, cdk::expression_node *right) :
        zu::lvalue_node(lineno) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_indexation_node(this, level);
    }

  };

} // zu

#endif