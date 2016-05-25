// $Id: zuidentifier_node.h,v 1.5 2016/05/20 12:44:37 ist178929 Exp $ -*- c++ -*-
#ifndef __ZU_AST_EXPRESSION_ZUIDENTIFIER_H__
#define __ZU_AST_EXPRESSION_ZUIDENTIFIER_H__

#include <cdk/ast/simple_value_node.h>
#include <ast/lvalue_node.h>
#include <string>

namespace zu {

  /**
   * Class for describing syntactic tree leaves for holding identifier
   * values.
   */
  class zuidentifier_node: public zu::lvalue_node {
      
      std::string _id;
  public:
    inline zuidentifier_node(int lineno) :
        zu::lvalue_node(lineno) {
    }
    inline zuidentifier_node(int lineno, std::string &s) :
        zu::lvalue_node(lineno), _id(s) {
    }
    inline zuidentifier_node(int lineno, std::string *s) :
        zu::lvalue_node(lineno), _id(*s) {
    }
    
    std::string id(){
        return _id;
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_zuidentifier_node(this, level);
    }

  };

} // ZU

#endif
