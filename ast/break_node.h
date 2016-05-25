#ifndef __ZU_BREAKNODE_H__
#define __ZU_BREAKNODE_H__

#include <cdk/ast/basic_node.h>

namespace zu {

  class break_node: public cdk::basic_node {

  public:
    inline break_node(int lineno) :
        cdk::basic_node(lineno) {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_break_node(this, level);
    }

  };

} // zu

#endif