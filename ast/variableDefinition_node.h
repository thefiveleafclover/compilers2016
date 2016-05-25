#ifndef __ZU_VARIABLEDEFINITIONNNODE_H__
#define __ZU_VARIABLEDEFINITIONNODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/basic_type.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>



namespace zu {

  class variableDefinition_node: public zu::variableDeclaration_node {
      cdk::expression_node *_value;
      
      
      
  public:
    inline variableDefinition_node(int lineno, bool ispublic, bool isconst, basic_type *type, zuidentifier_node *id, cdk::expression_node *value)  :
        zu::variableDeclaration_node(lineno, ispublic, isconst, type, id), _value(value) {
    }

  public:
    inline cdk::expression_node *value(){
        return _value;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variableDefinition_node(this, level);
    }

  };

} // zu

#endif