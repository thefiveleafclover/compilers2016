#ifndef __ZU_EXPRESSIONASINSTRUCTIONNODE_H__
#define __ZU_EXPRESSIONASINSTRUCTIONNODE_H__

#include <cdk/ast/expression_node.h>

namespace zu {

  /**
   * Class for describing expressions as instructions nodes.
   */
  class expressionAsInstruction_node: public cdk::basic_node {
    cdk::expression_node *_expression;

  public:
    inline expressionAsInstruction_node(int lineno, cdk::expression_node *expression) :
        cdk::basic_node(lineno), _expression(expression) {
    }

  public:
    inline cdk::expression_node *expression() {
      return _expression;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_expressionAsInstruction_node(this, level);
    }

  };

} // zu

#endif