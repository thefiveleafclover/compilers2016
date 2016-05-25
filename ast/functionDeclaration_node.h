#ifndef __ZU_FUNCTIONDECLARATIONNODE_H__
#define __ZU_FUNCTIONDECLARATIONNODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/basic_type.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>


namespace zu{
  
    
    class functionDeclaration_node: public cdk::basic_node{
      bool						_public;
      bool						_exte;
      basic_type			   		*_type;
      zuidentifier_node 		                *_left;
      cdk::sequence_node		   		*_arguments;
      
      
    
    public:
      inline functionDeclaration_node(int lineno, basic_type *type, bool publica, bool exte, zuidentifier_node *left, cdk::sequence_node *args):
	cdk::basic_node(lineno), _public(publica), _exte(exte), _type(type), _left(left), _arguments(args){}
	
    public:
      
      inline bool publica(){
	return _public;
      }

      inline bool exte(){
          return _exte;
      }
      
      inline basic_type *type(){
	return _type;
      }
      
      inline zuidentifier_node *identifier(){
	return _left;
      }
      
      inline cdk::sequence_node *arguments(){
	return _arguments;
      }
      
      
      void public_scope(bool p){
	_public=p;
      }
      
      
      void accept(basic_ast_visitor *sp, int level){
	sp->do_functionDeclaration_node(this,level);
      }
    };//Class function_declaration_node
}//namespace zu

#endif 
