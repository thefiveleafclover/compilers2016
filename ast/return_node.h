#ifndef __ZU_RETURNNODE_H__
#define __ZU_RETURNNODE_H__

#include <cdk/ast/basic_node.h>

namespace zu {

  class return_node: public cdk::basic_node {

  public:
    inline return_node(int lineno) :
        cdk::basic_node(lineno){
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // zu

#endif
