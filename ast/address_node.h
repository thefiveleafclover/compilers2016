#ifndef __ZU_AST_ADDRESS_H__
#define __ZU_AST_ADDRESS_H__

#include <cdk/ast/unary_expression_node.h>

namespace zu {

  class address_node: public cdk::unary_expression_node {
  public:
    inline address_node(int lineno, expression_node *arg) :
        cdk::unary_expression_node(lineno, arg) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_address_node(this, level);
    }

  };

} // zu

#endif