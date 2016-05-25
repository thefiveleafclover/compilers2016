#ifndef __ZU_CONTINUENODE_H__
#define __ZU_CONTINUENODE_H__

#include <cdk/ast/basic_node.h>

namespace zu {

  class continue_node: public cdk::basic_node {

  public:
    inline continue_node(int lineno) :
        cdk::basic_node(lineno) {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_continue_node(this, level);
    }

  };

} // zu

#endif