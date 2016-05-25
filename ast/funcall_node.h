#ifndef __ZU_FUNCALL_H__
#define __ZU_FUNCALL_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>



namespace zu {

  /**
   * Class for describing funcall nodes.
   */
  class funcall_node: public cdk::expression_node {
    zuidentifier_node *_id;
    cdk::sequence_node * _arguments;

  public:
    inline funcall_node(int lineno, zuidentifier_node *id, cdk::sequence_node *arguments) :
        cdk::expression_node(lineno), _id(id), _arguments(arguments) {
    }

  public:
    inline zuidentifier_node *id() {
      return _id;
    }
    
    inline cdk::sequence_node *arguments() {
      return _arguments;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_funcall_node(this, level);
    }

  };

} // zu

#endif