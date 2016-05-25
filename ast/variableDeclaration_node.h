#ifndef __ZU_VARIABLEDECLARATIONNODE_H__
#define __ZU_VARIABLEDECLARATIONNODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/basic_type.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>



namespace zu {

  class variableDeclaration_node: public cdk::basic_node {
      bool _ispublic, _isconst;
      basic_type *_type;
      zuidentifier_node *_identifier;
      
      
  public:
    inline variableDeclaration_node(int lineno, bool ispublic, bool isconst, basic_type *type, zuidentifier_node *identifier)  :
        cdk::basic_node(lineno), _ispublic(ispublic), _isconst(isconst), _type(type), _identifier(identifier) {
    }

  public:
    inline bool ispublic(){
        return _ispublic;
    }

    inline bool isconst(){
        return _isconst;
    }
    
    inline basic_type *type(){
        return _type;
    }
    
    inline zuidentifier_node *identifier(){
        return _identifier;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variableDeclaration_node(this, level);
    }

  };

} // zu

#endif