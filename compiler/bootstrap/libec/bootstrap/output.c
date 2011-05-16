#if defined(__GNUC__)
typedef long long int64;
typedef unsigned long long uint64;
#elif defined(__TINYC__)
#include <stdarg.h>
#define __builtin_va_list va_list
#define __builtin_va_start va_start
#define __builtin_va_end va_end
#ifdef _WIN32
#define strcasecmp stricmp
#define strncasecmp strnicmp
#define __declspec(x) __attribute__((x))
#endif
typedef long long int64;
typedef unsigned long long uint64;
#else
typedef __int64 int64;
typedef unsigned __int64 uint64;
#endif
#ifdef __BIG_ENDIAN__
#define __ENDIAN_PAD(x) (8 - (x))
#else
#define __ENDIAN_PAD(x) 0
#endif
extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__sys__BTNode;

struct __ecereNameSpace__ecere__sys__BTNode;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__sys__BinaryTree;

struct __ecereNameSpace__ecere__sys__BinaryTree
{
struct __ecereNameSpace__ecere__sys__BTNode * root;
int count;
int (*  CompareKey)(struct __ecereNameSpace__ecere__sys__BinaryTree * tree, unsigned int a, unsigned int b);
void (*  FreeKey)(void *  key);
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__sys__OldList;

struct __ecereNameSpace__ecere__sys__OldList
{
void *  first;
void *  last;
int count;
unsigned int offset;
unsigned int circ;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Method;

struct __ecereNameSpace__ecere__com__Method
{
char *  name;
struct __ecereNameSpace__ecere__com__Method * parent;
struct __ecereNameSpace__ecere__com__Method * left;
struct __ecereNameSpace__ecere__com__Method * right;
int depth;
int (*  function)();
int vid;
int type;
struct __ecereNameSpace__ecere__com__Class * _class;
void *  symbol;
char *  dataTypeString;
struct Type * dataType;
int memberAccess;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Property;

struct __ecereNameSpace__ecere__com__Property
{
struct __ecereNameSpace__ecere__com__Property * prev;
struct __ecereNameSpace__ecere__com__Property * next;
char *  name;
unsigned int isProperty;
int memberAccess;
int id;
struct __ecereNameSpace__ecere__com__Class * _class;
char *  dataTypeString;
struct __ecereNameSpace__ecere__com__Class * dataTypeClass;
struct Type * dataType;
void (*  Set)();
int (*  Get)();
unsigned int (*  IsSet)();
void *  data;
void *  symbol;
int vid;
unsigned int conversion;
unsigned int watcherOffset;
char *  category;
unsigned int compiled;
unsigned int selfWatchable;
unsigned int isWatchable;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_CodePosition;

struct CodePosition
{
int line;
int charPos;
int pos;
unsigned int included;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Location;

struct Location
{
struct CodePosition start;
struct CodePosition end;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ClassDefinition;

struct ClassDefinition
{
struct ClassDefinition * prev;
struct ClassDefinition * next;
struct Location loc;
struct Specifier * _class;
struct __ecereNameSpace__ecere__sys__OldList *  baseSpecs;
struct __ecereNameSpace__ecere__sys__OldList *  definitions;
struct Symbol * symbol;
struct Location blockStart;
struct Location nameLoc;
int endid;
int declMode;
unsigned int deleteWatchable;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Context;

struct Context;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Instantiation;

struct Instantiation
{
struct Instantiation * prev;
struct Instantiation * next;
struct Location loc;
struct Specifier * _class;
struct Expression * exp;
struct __ecereNameSpace__ecere__sys__OldList *  members;
struct Symbol * symbol;
unsigned int fullSet;
unsigned int isConstant;
unsigned char *  data;
struct Location nameLoc;
struct Location insideLoc;
unsigned int built;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Declaration;

struct Declaration
{
struct Declaration * prev;
struct Declaration * next;
struct Location loc;
int type;
union
{
struct
{
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct __ecereNameSpace__ecere__sys__OldList *  declarators;
};
struct Instantiation * inst;
struct
{
struct Identifier * id;
struct Expression * exp;
};
};
struct Specifier * extStorage;
struct Symbol * symbol;
int declMode;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Statement;

struct Statement
{
struct Statement * prev;
struct Statement * next;
struct Location loc;
int type;
union
{
struct __ecereNameSpace__ecere__sys__OldList *  expressions;
struct
{
struct Identifier * id;
struct Statement * stmt;
} labeled;
struct
{
struct Expression * exp;
struct Statement * stmt;
} caseStmt;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * declarations;
struct __ecereNameSpace__ecere__sys__OldList * statements;
struct Context * context;
unsigned int isSwitch;
} compound;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Statement * stmt;
struct Statement * elseStmt;
} ifStmt;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Statement * stmt;
} switchStmt;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Statement * stmt;
} whileStmt;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Statement * stmt;
} doWhile;
struct
{
struct Statement * init;
struct Statement * check;
struct __ecereNameSpace__ecere__sys__OldList * increment;
struct Statement * stmt;
} forStmt;
struct
{
struct Identifier * id;
} gotoStmt;
struct
{
struct Specifier * spec;
char * statements;
struct __ecereNameSpace__ecere__sys__OldList * inputFields;
struct __ecereNameSpace__ecere__sys__OldList * outputFields;
struct __ecereNameSpace__ecere__sys__OldList * clobberedFields;
} asmStmt;
struct
{
struct Expression * watcher;
struct Expression * object;
struct __ecereNameSpace__ecere__sys__OldList * watches;
} _watch;
struct
{
struct Identifier * id;
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct __ecereNameSpace__ecere__sys__OldList * filter;
struct Statement * stmt;
} forEachStmt;
struct Declaration * decl;
};
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TypeName;

struct TypeName
{
struct TypeName * prev;
struct TypeName * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  qualifiers;
struct Declarator * declarator;
int classObjectType;
struct Expression * bitCount;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Initializer;

struct Initializer
{
struct Initializer * prev;
struct Initializer * next;
struct Location loc;
int type;
union
{
struct Expression * exp;
struct __ecereNameSpace__ecere__sys__OldList *  list;
};
unsigned int isConstant;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__DataValue;

struct __ecereNameSpace__ecere__com__DataValue
{
union
{
char c;
unsigned char uc;
short s;
unsigned short us;
int i;
unsigned int ui;
void *  p;
float f;
double d;
long long i64;
uint64 ui64;
};
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Expression;

struct Expression
{
struct Expression * prev;
struct Expression * next;
struct Location loc;
int type;
union
{
struct
{
char *  constant;
struct Identifier * identifier;
};
struct Statement * compound;
struct Instantiation * instance;
char *  string;
struct __ecereNameSpace__ecere__sys__OldList *  list;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * specifiers;
struct Declarator * decl;
} _classExp;
struct
{
struct Identifier * id;
} classData;
struct
{
struct Expression * exp;
struct __ecereNameSpace__ecere__sys__OldList * arguments;
struct Location argLoc;
} call;
struct
{
struct Expression * exp;
struct __ecereNameSpace__ecere__sys__OldList * index;
} index;
struct
{
struct Expression * exp;
struct Identifier * member;
int memberType;
unsigned int thisPtr;
} member;
struct
{
int op;
struct Expression * exp1;
struct Expression * exp2;
} op;
struct TypeName * typeName;
struct Specifier * _class;
struct
{
struct TypeName * typeName;
struct Expression * exp;
} cast;
struct
{
struct Expression * cond;
struct __ecereNameSpace__ecere__sys__OldList * exp;
struct Expression * elseExp;
} cond;
struct
{
struct TypeName * typeName;
struct Expression * size;
} _new;
struct
{
struct TypeName * typeName;
struct Expression * size;
struct Expression * exp;
} _renew;
struct
{
char * table;
struct Identifier * id;
} db;
struct
{
struct Expression * ds;
struct Expression * name;
} dbopen;
struct
{
struct TypeName * typeName;
struct Initializer * initializer;
} initializer;
struct
{
struct Expression * exp;
struct TypeName * typeName;
} vaArg;
};
unsigned int debugValue;
struct __ecereNameSpace__ecere__com__DataValue val;
unsigned int address;
unsigned int hasAddress;
struct Type * expType;
struct Type * destType;
unsigned int usage;
int tempCount;
unsigned int byReference;
unsigned int isConstant;
unsigned int addedThis;
unsigned int needCast;
unsigned int thisPtr;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TemplateDatatype;

struct TemplateDatatype
{
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct Declarator * decl;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TemplateArgument;

struct TemplateArgument;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_TemplateParameter;

struct TemplateParameter
{
struct TemplateParameter * prev;
struct TemplateParameter * next;
struct Location loc;
int type;
struct Identifier * identifier;
union
{
struct TemplateDatatype * dataType;
int memberType;
};
struct TemplateArgument * defaultArgument;
char *  dataTypeString;
struct Type * baseType;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Specifier;

struct Specifier
{
struct Specifier * prev;
struct Specifier * next;
struct Location loc;
int type;
union
{
int specifier;
struct
{
char *  name;
struct Symbol * symbol;
struct __ecereNameSpace__ecere__sys__OldList *  templateArgs;
};
struct
{
struct Identifier * id;
struct __ecereNameSpace__ecere__sys__OldList *  list;
struct __ecereNameSpace__ecere__sys__OldList *  baseSpecs;
struct __ecereNameSpace__ecere__sys__OldList *  definitions;
unsigned int addNameSpace;
struct Context * ctx;
};
struct Expression * expression;
struct Specifier * _class;
struct TemplateParameter * templateParameter;
};
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Identifier;

struct Identifier
{
struct Identifier * prev;
struct Identifier * next;
struct Location loc;
struct Symbol * classSym;
struct Specifier * _class;
char *  string;
struct Identifier * badID;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Pointer;

struct Pointer
{
struct Pointer * prev;
struct Pointer * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  qualifiers;
struct Pointer * pointer;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Declarator;

struct Declarator
{
struct Declarator * prev;
struct Declarator * next;
struct Location loc;
int type;
struct Symbol * symbol;
struct Declarator * declarator;
union
{
struct Identifier * identifier;
struct
{
struct Expression * exp;
struct Expression * posExp;
char * attrib;
} structDecl;
struct
{
struct Expression * exp;
struct Specifier * enumClass;
} array;
struct
{
struct __ecereNameSpace__ecere__sys__OldList * parameters;
} function;
struct
{
struct Pointer * pointer;
} pointer;
struct
{
char * extended;
} extended;
};
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_FunctionDefinition;

struct FunctionDefinition
{
struct FunctionDefinition * prev;
struct FunctionDefinition * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct Declarator * declarator;
struct __ecereNameSpace__ecere__sys__OldList *  declarations;
struct Statement * body;
struct __ecereNameSpace__ecere__com__Class * _class;
struct __ecereNameSpace__ecere__sys__OldList attached;
int declMode;
struct Type * type;
struct Symbol * propSet;
int tempCount;
unsigned int propertyNoThis;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_DBTableDef;

struct DBTableDef;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_External;

struct External
{
struct External * prev;
struct External * next;
struct Location loc;
int type;
struct Symbol * symbol;
union
{
struct FunctionDefinition * function;
struct ClassDefinition * _class;
struct Declaration * declaration;
char *  importString;
struct Identifier * id;
struct DBTableDef * table;
};
int importType;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ModuleImport;

struct ModuleImport;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ClassImport;

struct ClassImport;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Symbol;

struct Symbol
{
char *  string;
struct Symbol * parent;
struct Symbol * left;
struct Symbol * right;
int depth;
struct Type * type;
union
{
struct __ecereNameSpace__ecere__com__Method * method;
struct __ecereNameSpace__ecere__com__Property * _property;
struct __ecereNameSpace__ecere__com__Class * registered;
};
int id;
int idCode;
union
{
struct
{
struct External * pointerExternal;
struct External * structExternal;
};
struct
{
struct External * externalGet;
struct External * externalSet;
struct External * externalPtr;
struct External * externalIsSet;
};
struct
{
struct External * methodExternal;
struct External * methodCodeExternal;
};
};
unsigned int imported;
unsigned int declaredStructSym;
struct __ecereNameSpace__ecere__com__Class * _class;
unsigned int declaredStruct;
unsigned int needConstructor;
unsigned int needDestructor;
char *  constructorName;
char *  structName;
char *  className;
char *  destructorName;
struct ModuleImport * module;
struct ClassImport * _import;
struct Location nameLoc;
unsigned int isParam;
unsigned int isRemote;
unsigned int isStruct;
unsigned int fireWatchersDone;
int declaring;
unsigned int classData;
unsigned int isStatic;
char *  shortName;
struct __ecereNameSpace__ecere__sys__OldList *  templateParams;
struct __ecereNameSpace__ecere__sys__OldList templatedClasses;
struct Context * ctx;
int isIterator;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Type;

struct Type
{
struct Type * prev;
struct Type * next;
int refCount;
union
{
struct Symbol * _class;
struct
{
struct __ecereNameSpace__ecere__sys__OldList members;
char *  enumName;
};
struct
{
struct Type * returnType;
struct __ecereNameSpace__ecere__sys__OldList params;
struct Symbol * thisClass;
unsigned int staticMethod;
struct TemplateParameter * thisClassTemplate;
};
struct
{
struct __ecereNameSpace__ecere__com__Method * method;
struct __ecereNameSpace__ecere__com__Class * methodClass;
struct __ecereNameSpace__ecere__com__Class * usedClass;
};
struct
{
struct Type * arrayType;
int arraySize;
struct Expression * arraySizeExp;
unsigned int freeExp;
struct Symbol * enumClass;
};
struct Type * type;
struct TemplateParameter * templateParameter;
};
unsigned int isSigned;
int kind;
unsigned int constant;
unsigned int size;
char *  name;
char *  typeName;
unsigned int count;
unsigned int truth;
int classObjectType;
unsigned int byReference;
unsigned int extraParam;
int alignment;
unsigned int directClassAccess;
unsigned int computing;
unsigned int dllExport;
unsigned int offset;
unsigned int keepCast;
unsigned int passAsTemplate;
int bitFieldCount;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Class;

struct __ecereNameSpace__ecere__com__Class
{
struct __ecereNameSpace__ecere__com__Class * prev;
struct __ecereNameSpace__ecere__com__Class * next;
char *  name;
int offset;
int structSize;
int (* *  _vTbl)();
int vTblSize;
int (*  Constructor)(struct __ecereNameSpace__ecere__com__Instance *);
void (*  Destructor)(struct __ecereNameSpace__ecere__com__Instance *);
int offsetClass;
int sizeClass;
struct __ecereNameSpace__ecere__com__Class * base;
struct __ecereNameSpace__ecere__sys__BinaryTree methods;
struct __ecereNameSpace__ecere__sys__BinaryTree members;
struct __ecereNameSpace__ecere__sys__BinaryTree prop;
struct __ecereNameSpace__ecere__sys__OldList membersAndProperties;
struct __ecereNameSpace__ecere__sys__BinaryTree classProperties;
struct __ecereNameSpace__ecere__sys__OldList derivatives;
int memberID;
int startMemberID;
int type;
struct __ecereNameSpace__ecere__com__Instance * module;
struct __ecereNameSpace__ecere__com__NameSpace *  nameSpace;
char *  dataTypeString;
struct Type * dataType;
int typeSize;
int defaultAlignment;
void (*  Initialize)();
int memberOffset;
struct __ecereNameSpace__ecere__sys__OldList selfWatchers;
char *  designerClass;
unsigned int noExpansion;
char *  defaultProperty;
unsigned int comRedefinition;
int count;
unsigned int isRemote;
unsigned int internalDecl;
void *  data;
unsigned int computeSize;
int structAlignment;
int destructionWatchOffset;
unsigned int fixed;
struct __ecereNameSpace__ecere__sys__OldList delayedCPValues;
int inheritanceAccess;
char *  fullName;
void *  symbol;
struct __ecereNameSpace__ecere__sys__OldList conversions;
struct __ecereNameSpace__ecere__sys__OldList templateParams;
struct __ecereNameSpace__ecere__com__ClassTemplateArgument *  templateArgs;
struct __ecereNameSpace__ecere__com__Class * templateClass;
struct __ecereNameSpace__ecere__sys__OldList templatized;
int numParams;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__Instance;

struct __ecereNameSpace__ecere__com__Instance
{
int (* *  _vTbl)();
struct __ecereNameSpace__ecere__com__Class * _class;
int _refCount;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__DataMember;

struct __ecereNameSpace__ecere__com__DataMember
{
struct __ecereNameSpace__ecere__com__DataMember * prev;
struct __ecereNameSpace__ecere__com__DataMember * next;
char *  name;
unsigned int isProperty;
int memberAccess;
int id;
struct __ecereNameSpace__ecere__com__Class * _class;
char *  dataTypeString;
struct __ecereNameSpace__ecere__com__Class * dataTypeClass;
struct Type * dataType;
int type;
int offset;
int memberID;
struct __ecereNameSpace__ecere__sys__OldList members;
struct __ecereNameSpace__ecere__sys__BinaryTree membersAlpha;
int memberOffset;
int structAlignment;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__SerialBuffer;

struct __ecereNameSpace__ecere__com__SerialBuffer
{
unsigned char *  _buffer;
unsigned int count;
unsigned int _size;
unsigned int pos;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__ClassTemplateArgument;

struct __ecereNameSpace__ecere__com__ClassTemplateArgument
{
union
{
struct
{
char *  dataTypeString;
struct __ecereNameSpace__ecere__com__Class * dataTypeClass;
};
struct __ecereNameSpace__ecere__com__DataValue expression;
struct
{
char *  memberString;
union
{
struct __ecereNameSpace__ecere__com__DataMember * member;
struct __ecereNameSpace__ecere__com__Property * prop;
struct __ecereNameSpace__ecere__com__Method * method;
};
};
};
};

typedef union YYSTYPE
{
int specifierType;
int i;
int declMode;
struct Identifier * id;
struct Expression * exp;
struct Specifier * specifier;
struct __ecereNameSpace__ecere__sys__OldList * list;
struct Enumerator * enumerator;
struct Declarator * declarator;
struct Pointer * pointer;
struct Initializer * initializer;
struct InitDeclarator * initDeclarator;
struct TypeName * typeName;
struct Declaration * declaration;
struct Statement * stmt;
struct FunctionDefinition * function;
struct External * external;
struct Context * context;
struct AsmField * asmField;
struct Instantiation * instance;
struct MembersInit * membersInit;
struct MemberInit * memberInit;
struct ClassFunction * classFunction;
struct ClassDefinition * _class;
struct ClassDef * classDef;
struct PropertyDef * prop;
char * string;
struct Symbol * symbol;
struct PropertyWatch * propertyWatch;
struct TemplateParameter * templateParameter;
struct TemplateArgument * templateArgument;
struct TemplateDatatype * templateDatatype;
struct DBTableEntry * dbtableEntry;
struct DBIndexItem * dbindexItem;
struct DBTableDef * dbtableDef;
} YYSTYPE;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_Enumerator;

struct Enumerator
{
struct Enumerator * prev;
struct Enumerator * next;
struct Location loc;
struct Identifier * id;
struct Expression * exp;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_InitDeclarator;

struct InitDeclarator
{
struct InitDeclarator * prev;
struct InitDeclarator * next;
struct Location loc;
struct Declarator * declarator;
struct Initializer * initializer;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_AsmField;

struct AsmField
{
struct AsmField * prev;
struct AsmField * next;
struct Location loc;
char *  command;
struct Expression * expression;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ClassFunction;

struct ClassFunction
{
struct ClassFunction * prev;
struct ClassFunction * next;
struct Location loc;
struct __ecereNameSpace__ecere__sys__OldList *  specifiers;
struct Declarator * declarator;
struct __ecereNameSpace__ecere__sys__OldList *  declarations;
struct Statement * body;
struct __ecereNameSpace__ecere__com__Class * _class;
struct __ecereNameSpace__ecere__sys__OldList attached;
int declMode;
struct Type * type;
struct Symbol * propSet;
unsigned int isVirtual;
unsigned int isConstructor;
unsigned int isDestructor;
unsigned int dontMangle;
int id;
int idCode;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_MembersInit;

struct MembersInit
{
struct MembersInit * prev;
struct MembersInit * next;
struct Location loc;
int type;
union
{
struct __ecereNameSpace__ecere__sys__OldList *  dataMembers;
struct ClassFunction * function;
};
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_MemberInit;

struct MemberInit
{
struct MemberInit * prev;
struct MemberInit * next;
struct Location loc;
struct Location realLoc;
struct __ecereNameSpace__ecere__sys__OldList *  identifiers;
struct Initializer * initializer;
unsigned int used;
unsigned int variable;
unsigned int takeOutExp;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_PropertyDef;

struct PropertyDef;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_PropertyWatch;

struct PropertyWatch;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_ClassDef;

struct ClassDef
{
struct ClassDef * prev;
struct ClassDef * next;
struct Location loc;
int type;
union
{
struct Declaration * decl;
struct ClassFunction * function;
struct __ecereNameSpace__ecere__sys__OldList *  defProperties;
struct PropertyDef * propertyDef;
struct PropertyWatch * propertyWatch;
char *  designer;
struct Identifier * defaultProperty;
struct
{
struct Identifier * id;
struct Initializer * initializer;
};
};
int memberAccess;
void *  object;
};

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_DBTableEntry;

struct DBTableEntry;

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass_DBIndexItem;

struct DBIndexItem;

extern YYSTYPE yylval;

extern struct Location yylloc;

int outputLine;

unsigned int memoryGuard = 0x0;

void SetMemoryGuard(unsigned int b)
{
memoryGuard = b;
}

unsigned int GetMemoryGuard()
{
return memoryGuard;
}

extern int strcmp(const char * , const char * );

int __ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts;

static void OutputIdentifier(struct Identifier * id, struct __ecereNameSpace__ecere__com__Instance * f)
{
if(id)
{
if(id->_class)
{
if(id->_class->type == 8)
{
if(id->_class->templateParameter && id->_class->templateParameter->identifier && id->_class->templateParameter->identifier->string)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, id->_class->templateParameter->identifier->string);
}
else
{
if(id->_class->name)
{
if(!strcmp(id->_class->name, "class"))
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "typed_object");
else
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, id->_class->name);
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "::");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, (id && id->string) ? id->string : "(null identifier)");
}

int __ecereVMethodID___ecereNameSpace__ecere__sys__File_Putc;

static void OutputOperator(int op, struct __ecereNameSpace__ecere__com__Instance * f)
{
switch(op)
{
case 263:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "++");
break;
case 264:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "--");
break;
case 261:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "sizeof ");
break;
case 265:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "<<");
break;
case 266:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ">>");
break;
case 267:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "<=");
break;
case 268:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ">=");
break;
case 269:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "==");
break;
case 270:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "!=");
break;
case 271:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "&&");
break;
case 272:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "||");
break;
case 273:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "*=");
break;
case 274:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "/=");
break;
case 275:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "%=");
break;
case 276:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "+=");
break;
case 277:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "-=");
break;
case 278:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "<<=");
break;
case 279:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ">>=");
break;
case 280:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "&=");
break;
case 281:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "^=");
break;
case 282:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "|=");
break;
case '&':
case '*':
case '+':
case '-':
case '~':
case '!':
case '/':
case '%':
case '<':
case '>':
case '|':
case '^':
case '=':
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, char ch))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Putc])(f, (char)op);
break;
case 328:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "delete ");
break;
}
}

static void OutputSpecifier(struct Specifier * spec, struct __ecereNameSpace__ecere__com__Instance * f);

static void OutputDeclarator(struct Declarator * decl, struct __ecereNameSpace__ecere__com__Instance * f);

void OutputTypeName(struct TypeName * type, struct __ecereNameSpace__ecere__com__Instance * f)
{
if(type->qualifiers)
{
struct Specifier * spec;

for(spec = (*type->qualifiers).first; spec; spec = spec->next)
{
OutputSpecifier(spec, f);
if(spec->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
}
if(type->declarator)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputDeclarator(type->declarator, f);
}
if(!type->qualifiers && !type->declarator)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "...");
}

static void OutputStatement(struct Statement * stmt, struct __ecereNameSpace__ecere__com__Instance * f);

static void OutputInstance(struct Instantiation * inst, struct __ecereNameSpace__ecere__com__Instance * f);

extern int printf(char * , ...);

static void OutputInitializer(struct Initializer * initializer, struct __ecereNameSpace__ecere__com__Instance * f);

void OutputExpression(struct Expression * exp, struct __ecereNameSpace__ecere__com__Instance * f)
{
switch(exp->type)
{
case 26:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "class(");
if(exp->_classExp.specifiers)
{
struct Specifier * spec;

for(spec = (*exp->_classExp.specifiers).first; spec; spec = spec->next)
{
OutputSpecifier(spec, f);
if(spec->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
if(exp->_classExp.decl)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputDeclarator(exp->_classExp.decl, f);
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
}
break;
case 25:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "__extension__ (");
OutputStatement(exp->compound, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
case 13:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "new ");
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputTypeName(exp->_renew.typeName, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "[");
OutputExpression(exp->_renew.size, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "]");
break;
case 28:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "new0 ");
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputTypeName(exp->_renew.typeName, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "[");
OutputExpression(exp->_renew.size, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "]");
break;
case 14:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "renew ");
OutputExpression(exp->_renew.exp, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputTypeName(exp->_renew.typeName, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "[");
OutputExpression(exp->_renew.size, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "]");
break;
case 29:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "renew0 ");
OutputExpression(exp->_renew.exp, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputTypeName(exp->_renew.typeName, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "[");
OutputExpression(exp->_renew.size, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "]");
break;
case 0:
if(exp->identifier)
OutputIdentifier(exp->identifier, f);
break;
case 1:
if(exp->instance)
OutputInstance(exp->instance, f);
break;
case 2:
if(exp->constant)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, exp->constant);
else
printf("");
break;
case 3:
if(exp->string)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, exp->string);
break;
case 4:
if(exp->op.exp1)
{
OutputExpression(exp->op.exp1, f);
if(exp->op.exp2)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
OutputOperator(exp->op.op, f);
if(exp->op.exp2)
{
if(exp->op.exp1 || (exp->op.exp2->type == 4 && !exp->op.exp2->op.exp1 && exp->op.exp2->op.op == exp->op.op))
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputExpression(exp->op.exp2, f);
}
break;
case 34:
case 5:
{
struct Expression * expression;

if(exp->type == 34)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "__extension__ (");
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "(");
if(exp->list)
{
for(expression = (*exp->list).first; expression; expression = expression->next)
{
OutputExpression(expression, f);
if(expression->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
}
case 6:
{
struct Expression * expression;

if(exp->index.exp)
OutputExpression(exp->index.exp, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "[");
if(exp->index.index)
for(expression = (*exp->index.index).first; expression; expression = expression->next)
{
OutputExpression(expression, f);
if(expression->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "]");
break;
}
case 7:
{
OutputExpression(exp->call.exp, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "(");
if(exp->call.arguments)
{
struct Expression * expression;

for(expression = (*exp->call.arguments).first; expression; expression = expression->next)
{
OutputExpression(expression, f);
if(expression->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
}
case 8:
if(exp->member.exp)
OutputExpression(exp->member.exp, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ".");
if(exp->member.member)
OutputIdentifier(exp->member.member, f);
break;
case 9:
OutputExpression(exp->member.exp, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "->");
OutputIdentifier(exp->member.member, f);
break;
case 10:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "sizeof(");
OutputTypeName(exp->typeName, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
case 35:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "__extension__ (");
if(exp->initializer.typeName)
OutputTypeName(exp->initializer.typeName, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
if(exp->initializer.initializer)
OutputInitializer(exp->initializer.initializer, f);
break;
case 11:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "(");
OutputTypeName(exp->cast.typeName, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
if(exp->cast.exp)
OutputExpression(exp->cast.exp, f);
break;
case 12:
OutputExpression(exp->cond.cond, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ? ");
{
struct Expression * expression;

for(expression = (*exp->cond.exp).first; expression; expression = expression->next)
{
OutputExpression(expression, f);
if(expression->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " : ");
OutputExpression(exp->cond.elseExp, f);
break;
case 36:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "__builtin_va_arg(");
OutputExpression(exp->vaArg.exp, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
OutputTypeName(exp->vaArg.typeName, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
case 37:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "[");
if(exp->list)
{
struct Expression * expression;

for(expression = (*exp->list).first; expression; expression = expression->next)
{
OutputExpression(expression, f);
if(expression->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "]");
break;
}
}

static void OutputAsmField(struct AsmField * field, struct __ecereNameSpace__ecere__com__Instance * f)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, field->command);
if(field->expression)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "(");
OutputExpression(field->expression, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
}
}

extern unsigned int inCompiler;

extern char *  __ecereNameSpace__ecere__sys__PathCat(char *  string, char *  addedPath);

extern char *  GetIncludeFileFromID(int id);

extern char *  sourceFile;

extern void __ecereNameSpace__ecere__sys__ChangeCh(char *  string, char ch1, char ch2);

extern char *  outputFile;

extern unsigned int outputLineNumbers;

static void OutputDeclaration(struct Declaration * decl, struct __ecereNameSpace__ecere__com__Instance * f);

extern struct __ecereNameSpace__ecere__sys__OldList *  MkList(void);

extern struct Declarator * SpecDeclFromString(char *  string, struct __ecereNameSpace__ecere__sys__OldList *  specs, struct Declarator * baseDecl);

extern struct Declarator * MkDeclaratorIdentifier(struct Identifier * id);

extern struct Identifier * MkIdentifier(char *  string);

extern struct __ecereNameSpace__ecere__sys__OldList *  CopyList(struct __ecereNameSpace__ecere__sys__OldList *  source, void *  (* )(void * ));

extern struct Specifier * CopySpecifier(struct Specifier * spec);

extern struct Declarator * PlugDeclarator(struct Declarator * decl, struct Declarator * baseDecl);

extern void ListAdd(struct __ecereNameSpace__ecere__sys__OldList * list, void *  item);

extern struct Specifier * MkSpecifierName(char *  name);

extern void PrintType(struct Type * type, char *  string, unsigned int printName, unsigned int fullName);

extern struct TypeName * MkTypeName(struct __ecereNameSpace__ecere__sys__OldList * qualifiers, struct Declarator * declarator);

extern void InstDeclPassTypeName(struct TypeName * type, unsigned int param);

extern void FreeTypeName(struct TypeName * typeName);

int __ecereMethod___ecereNameSpace__ecere__sys__File_Printf(struct __ecereNameSpace__ecere__com__Instance * this, char *  format, ...);

static void OutputStatement(struct Statement * stmt, struct __ecereNameSpace__ecere__com__Instance * f)
{
char name[274] = "";
char origName[274] = "";

if(inCompiler)
{
if(yylloc.start.included)
{
__ecereNameSpace__ecere__sys__PathCat(name, GetIncludeFileFromID((unsigned int)yylloc.start.included));
}
else if(sourceFile)
{
__ecereNameSpace__ecere__sys__PathCat(name, sourceFile);
}
__ecereNameSpace__ecere__sys__ChangeCh(name, '\\', '/');
__ecereNameSpace__ecere__sys__PathCat(origName, outputFile);
__ecereNameSpace__ecere__sys__ChangeCh(origName, '\\', '/');
}
if(inCompiler && outputLineNumbers && stmt->loc.start.line)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "\n#line %d \"%s\"\n", stmt->loc.start.line, name);
outputLine += 2;
}
switch(stmt->type)
{
case 0:
OutputIdentifier(stmt->labeled.id, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ":\n");
outputLine++;
OutputStatement(stmt->labeled.stmt, f);
break;
case 1:
if(stmt->caseStmt.exp)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "case ");
OutputExpression(stmt->caseStmt.exp, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ":\n");
outputLine++;
}
else
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "default:\n");
outputLine++;
}
if(stmt->caseStmt.stmt)
OutputStatement(stmt->caseStmt.stmt, f);
break;
case 2:
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "{\n");
outputLine++;
if(stmt->compound.declarations)
{
struct Declaration * decl;

for(decl = (*stmt->compound.declarations).first; decl; decl = decl->next)
{
OutputDeclaration(decl, f);
}
}
if(stmt->compound.statements)
{
struct Statement * statement;

if(stmt->compound.declarations)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
}
for(statement = (*stmt->compound.statements).first; statement; statement = statement->next)
{
OutputStatement(statement, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
}
}
if(inCompiler && outputLineNumbers && stmt->loc.end.line)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "\n#line %d \"%s\"\n", stmt->loc.end.line, name);
outputLine += 2;
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "}");
break;
}
case 3:
{
if(stmt->expressions)
{
struct Expression * exp;

for(exp = (*stmt->expressions).first; exp; exp = exp->next)
{
OutputExpression(exp, f);
if(exp->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ";");
break;
}
case 4:
{
struct Expression * exp;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "if(");
for(exp = (*stmt->ifStmt.exp).first; exp; exp = exp->next)
{
OutputExpression(exp, f);
if(exp->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")\n");
outputLine++;
if(stmt->ifStmt.stmt)
OutputStatement(stmt->ifStmt.stmt, f);
if(stmt->ifStmt.elseStmt)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "else");
if(stmt->ifStmt.elseStmt->type != 4)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
}
else
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputStatement(stmt->ifStmt.elseStmt, f);
}
break;
}
case 5:
{
struct Expression * exp;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "switch(");
for(exp = (*stmt->switchStmt.exp).first; exp; exp = exp->next)
{
OutputExpression(exp, f);
if(exp->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")\n");
outputLine++;
OutputStatement(stmt->switchStmt.stmt, f);
break;
}
case 6:
{
struct Expression * exp;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "while(");
for(exp = (*stmt->switchStmt.exp).first; exp; exp = exp->next)
{
OutputExpression(exp, f);
if(exp->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")\n");
outputLine++;
OutputStatement(stmt->whileStmt.stmt, f);
break;
}
case 7:
{
struct Expression * exp;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "do\n");
outputLine++;
OutputStatement(stmt->whileStmt.stmt, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "while(");
for(exp = (*stmt->switchStmt.exp).first; exp; exp = exp->next)
{
OutputExpression(exp, f);
if(exp->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ");");
break;
}
case 8:
{
struct Expression * exp;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "for(");
OutputStatement(stmt->forStmt.init, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputStatement(stmt->forStmt.check, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
if(stmt->forStmt.increment)
{
if(inCompiler && outputLineNumbers && stmt->loc.end.line)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "\n#line %d \"%s\"\n", stmt->loc.end.line, name);
outputLine += 2;
}
for(exp = (*stmt->forStmt.increment).first; exp; exp = exp->next)
{
OutputExpression(exp, f);
if(exp->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")\n");
outputLine++;
OutputStatement(stmt->forStmt.stmt, f);
break;
}
case 9:
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "goto ");
OutputIdentifier(stmt->gotoStmt.id, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ";");
break;
}
case 10:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "continue;");
break;
case 11:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "break;");
break;
case 12:
{
struct Expression * exp;

if(inCompiler && memoryGuard)
{
struct Expression * exp = stmt->expressions ? (*stmt->expressions).last : (((void *)0));

__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "{ ");
if(exp && exp->expType)
{
char string[1024] = "";
struct __ecereNameSpace__ecere__sys__OldList * specs = MkList();
struct Declarator * decl;
struct TypeName * typeName;

if(exp->expType->kind == 20)
{
if(exp->expType->templateParameter->dataTypeString)
decl = SpecDeclFromString(exp->expType->templateParameter->dataTypeString, specs, MkDeclaratorIdentifier(MkIdentifier("__ecereReturnVal")));
else if(exp->expType->templateParameter->dataType)
{
(__ecereNameSpace__ecere__com__eSystem_Delete(specs), specs = 0);
specs = CopyList(exp->expType->templateParameter->dataType->specifiers, CopySpecifier);
decl = PlugDeclarator(exp->expType->templateParameter->dataType->decl, MkDeclaratorIdentifier(MkIdentifier("__ecereReturnVal")));
}
else
{
ListAdd(specs, MkSpecifierName("uint64"));
decl = MkDeclaratorIdentifier(MkIdentifier("__ecereReturnVal"));
}
}
else
{
PrintType(exp->expType, string, 0x1, 0x1);
decl = SpecDeclFromString(string, specs, MkDeclaratorIdentifier(MkIdentifier("__ecereReturnVal")));
}
typeName = MkTypeName(specs, decl);
InstDeclPassTypeName(typeName, 0x0);
OutputTypeName(typeName, f);
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, ";");
FreeTypeName(typeName);
}
}
if(!memoryGuard)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "return ");
else
{
struct Expression * exp = stmt->expressions ? (*stmt->expressions).last : (((void *)0));

if(exp && exp->expType)
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "__ecereReturnVal = ");
}
if(stmt->expressions)
{
for(exp = (*stmt->expressions).first; exp; exp = exp->next)
{
OutputExpression(exp, f);
if(exp->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ";");
if(inCompiler && memoryGuard)
{
struct Expression * exp = stmt->expressions ? (struct Expression *)(*stmt->expressions).last : (((void *)0));

__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, " __ecereNameSpace__ecere__com__MemoryGuard_PopLoc();");
if(exp && exp->expType)
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "return __ecereReturnVal;");
else
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "return;");
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "}");
}
break;
}
case 13:
{
struct AsmField * field;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "__asm__ ");
if(stmt->asmStmt.spec)
OutputSpecifier(stmt->asmStmt.spec, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "(");
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, stmt->asmStmt.statements);
if(stmt->asmStmt.inputFields || stmt->asmStmt.outputFields || stmt->asmStmt.clobberedFields)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ":");
if(stmt->asmStmt.inputFields)
{
for(field = (*stmt->asmStmt.inputFields).first; field; field = field->next)
{
if(field->prev)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ",");
OutputAsmField(field, f);
}
}
}
if(stmt->asmStmt.outputFields || stmt->asmStmt.clobberedFields)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ":");
if(stmt->asmStmt.outputFields)
{
for(field = (*stmt->asmStmt.outputFields).first; field; field = field->next)
{
if(field->prev)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ",");
OutputAsmField(field, f);
}
}
}
if(stmt->asmStmt.clobberedFields)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ":");
for(field = (*stmt->asmStmt.clobberedFields).first; field; field = field->next)
{
if(field->prev)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ",");
OutputAsmField(field, f);
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ");\n");
break;
}
}
if(inCompiler && outputLineNumbers && stmt->loc.start.line)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "\n#line %d \"%s\"\n", outputLine + 2, origName);
outputLine += 2;
}
}

static void OutputPointer(struct Pointer * ptr, struct __ecereNameSpace__ecere__com__Instance * f)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "*");
if(ptr->qualifiers)
{
struct Specifier * spec;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
for(spec = (*ptr->qualifiers).first; spec; spec = spec->next)
{
OutputSpecifier(spec, f);
if(spec->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
}
if(ptr->pointer)
{
OutputPointer(ptr->pointer, f);
}
}

extern void ProcessExpressionType(struct Expression * exp);

extern void ComputeExpression(struct Expression * exp);

extern int __ecereNameSpace__ecere__com__eClass_GetProperty(struct __ecereNameSpace__ecere__com__Class * _class, char *  name);

static void OutputDeclarator(struct Declarator * decl, struct __ecereNameSpace__ecere__com__Instance * f)
{
switch(decl->type)
{
case 0:
if(decl->declarator)
{
OutputDeclarator(decl->declarator, f);
}
if(decl->structDecl.exp)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " : ");
OutputExpression(decl->structDecl.exp, f);
}
if(decl->structDecl.posExp)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " : ");
OutputExpression(decl->structDecl.posExp, f);
}
if(decl->structDecl.attrib)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, decl->structDecl.attrib);
}
break;
case 1:
OutputIdentifier(decl->identifier, f);
break;
case 2:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "(");
OutputDeclarator(decl->declarator, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
case 6:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, decl->extended.extended);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputDeclarator(decl->declarator, f);
break;
case 7:
OutputDeclarator(decl->declarator, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, decl->extended.extended);
break;
case 3:
if(decl->declarator)
{
OutputDeclarator(decl->declarator, f);
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "[");
if(decl->array.exp)
{
ProcessExpressionType(decl->array.exp);
ComputeExpression(decl->array.exp);
OutputExpression(decl->array.exp, f);
}
else if(decl->array.enumClass)
{
struct Symbol * _class = decl->array.enumClass->symbol;

if(_class && _class->registered)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "%d", __ecereNameSpace__ecere__com__eClass_GetProperty(_class->registered, "enumSize"));
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "]");
break;
case 4:
{
struct TypeName * param;

if(decl->declarator)
OutputDeclarator(decl->declarator, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "(");
if(decl->function.parameters && (*decl->function.parameters).first)
{
for(param = (*decl->function.parameters).first; param; param = param->next)
{
OutputTypeName(param, f);
if(param->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
}
case 5:
if(decl->pointer.pointer)
OutputPointer(decl->pointer.pointer, f);
if(decl->declarator)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputDeclarator(decl->declarator, f);
}
break;
}
}

static void OutputEnumerator(struct Enumerator * enumerator, struct __ecereNameSpace__ecere__com__Instance * f)
{
OutputIdentifier(enumerator->id, f);
if(enumerator->exp)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " = ");
OutputExpression(enumerator->exp, f);
}
}

extern struct Symbol * FindClass(char *  name);

static void OutputClassDef(struct ClassDef * def, struct __ecereNameSpace__ecere__com__Instance * f);

static void OutputSpecifier(struct Specifier * spec, struct __ecereNameSpace__ecere__com__Instance * f)
{
switch(spec->type)
{
case 0:
switch(spec->specifier)
{
case 284:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "typedef");
break;
case 285:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "extern");
break;
case 286:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "static");
break;
case 287:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "auto");
break;
case 288:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "register");
break;
case 299:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "const");
break;
case 300:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "volatile");
break;
case 301:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "void");
break;
case 289:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "char");
break;
case 290:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "short");
break;
case 291:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "int");
break;
case 292:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "unsigned int");
break;
case 293:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "long long");
break;
case 302:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "__builtin_va_list");
break;
case 294:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "long");
break;
case 297:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "float");
break;
case 298:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "double");
break;
case 295:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "signed");
break;
case 296:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "unsigned");
break;
case 337:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "typed_object");
break;
case 338:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "any_object");
break;
case 320:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "class");
break;
case 321:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "thisclass");
break;
}
break;
case 5:
case 1:
if(spec->name && !strcmp(spec->name, "class"))
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "typed_object");
}
else
{
struct Symbol * symbol = spec->symbol;

if(!symbol && spec->name)
symbol = FindClass(spec->name);
if(symbol)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, symbol->string ? symbol->string : "(null)");
}
else if(spec->name)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, spec->name);
}
break;
case 2:
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "enum");
if(spec->id)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputIdentifier(spec->id, f);
}
if(spec->list)
{
struct Enumerator * enumerator;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n{\n");
outputLine += 2;
for(enumerator = (*spec->list).first; enumerator; enumerator = enumerator->next)
{
OutputEnumerator(enumerator, f);
if(enumerator->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n}");
outputLine++;
}
break;
}
case 3:
case 4:
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, (spec->type == 3) ? "struct" : "union");
if(spec->id)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputIdentifier(spec->id, f);
}
if(spec->definitions)
{
struct ClassDef * def;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n{\n");
outputLine += 2;
for(def = (*spec->definitions).first; def; def = def->next)
{
OutputClassDef(def, f);
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "}");
}
break;
}
case 6:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "__typeof(");
OutputExpression(spec->expression, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
case 7:
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "subclass(");
OutputSpecifier(spec->_class, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ")");
break;
case 8:
OutputIdentifier(spec->templateParameter->identifier, f);
break;
}
}

static void OutputInitializer(struct Initializer * initializer, struct __ecereNameSpace__ecere__com__Instance * f)
{
char name[274] = "";
char origName[274] = "";

if(inCompiler)
{
if(yylloc.start.included)
{
__ecereNameSpace__ecere__sys__PathCat(name, GetIncludeFileFromID((unsigned int)yylloc.start.included));
}
else if(sourceFile)
{
__ecereNameSpace__ecere__sys__PathCat(name, sourceFile);
}
__ecereNameSpace__ecere__sys__ChangeCh(name, '\\', '/');
__ecereNameSpace__ecere__sys__PathCat(origName, outputFile);
__ecereNameSpace__ecere__sys__ChangeCh(origName, '\\', '/');
}
switch(initializer->type)
{
case 1:
{
struct Initializer * init;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n{\n");
outputLine += 2;
if(inCompiler && outputLineNumbers && initializer->loc.start.line)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "\n#line %d \"%s\"\n", initializer->loc.start.line, name);
outputLine += 2;
}
for(init = (*initializer->list).first; init; init = init->next)
{
OutputInitializer(init, f);
if(init->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n}");
if(inCompiler && outputLineNumbers && initializer->loc.start.line)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "\n#line %d \"%s\"\n", initializer->loc.start.line, name);
outputLine += 2;
}
outputLine++;
break;
}
case 0:
if(initializer->exp)
OutputExpression(initializer->exp, f);
break;
}
}

static void OutputInitDeclarator(struct InitDeclarator * decl, struct __ecereNameSpace__ecere__com__Instance * f)
{
OutputDeclarator(decl->declarator, f);
if(decl->initializer)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " = ");
OutputInitializer(decl->initializer, f);
}
}

static void OutputDeclaration(struct Declaration * decl, struct __ecereNameSpace__ecere__com__Instance * f)
{
struct Specifier * spec;
char origName[274] = "";

switch(decl->type)
{
case 1:
{
struct InitDeclarator * d;

if(inCompiler)
{
__ecereNameSpace__ecere__sys__PathCat(origName, outputFile);
__ecereNameSpace__ecere__sys__ChangeCh(origName, '\\', '/');
}
if(decl->declarators && (*decl->declarators).first)
{
for(d = (*decl->declarators).first; d; d = d->next)
if(d->initializer)
{
char name[274] = "";

if(yylloc.start.included)
{
__ecereNameSpace__ecere__sys__PathCat(name, GetIncludeFileFromID((unsigned int)yylloc.start.included));
}
else if(sourceFile)
{
__ecereNameSpace__ecere__sys__PathCat(name, sourceFile);
}
__ecereNameSpace__ecere__sys__ChangeCh(name, '\\', '/');
if(inCompiler && outputLineNumbers && decl->loc.start.line)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "\n#line %d \"%s\"\n", decl->loc.start.line, name);
outputLine += 2;
}
break;
}
}
if(decl->specifiers)
{
for(spec = (*decl->specifiers).first; spec; spec = spec->next)
{
OutputSpecifier(spec, f);
if(spec->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
}
if(decl->declarators && (*decl->declarators).first)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
for(d = (*decl->declarators).first; d; d = d->next)
{
OutputInitDeclarator(d, f);
if(d->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
break;
}
case 0:
{
if(decl->specifiers)
{
for(spec = (*decl->specifiers).first; spec; spec = spec->next)
{
OutputSpecifier(spec, f);
if(spec->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
}
if(decl->declarators)
{
struct Declarator * d;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
for(d = (*decl->declarators).first; d; d = d->next)
{
OutputDeclarator(d, f);
if(d->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
if(decl->extStorage)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputSpecifier(decl->extStorage, f);
}
break;
}
case 2:
if(decl->inst)
{
OutputInstance(decl->inst, f);
}
break;
case 3:
return ;
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ";\n");
outputLine++;
if(inCompiler && outputLineNumbers && decl->loc.start.line && decl->type == 1)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "\n#line %d \"%s\"\n", outputLine + 2, origName);
outputLine += 2;
}
}

static struct FunctionDefinition * curFunction;

extern struct Identifier * GetDeclId(struct Declarator * decl);

static void OutputFunction(struct FunctionDefinition * func, struct __ecereNameSpace__ecere__com__Instance * f)
{
struct FunctionDefinition * oldFunc = curFunction;

curFunction = func;
if(func->specifiers)
{
struct Specifier * spec;

for(spec = (*func->specifiers).first; spec; spec = spec->next)
{
OutputSpecifier(spec, f);
if(spec->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
if(func->declarator)
OutputDeclarator(func->declarator, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
if(func->declarations)
{
struct Declaration * decl;

for(decl = (*func->declarations).first; decl; decl = decl->next)
{
OutputDeclaration(decl, f);
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
}
if(func->body)
{
if(inCompiler && memoryGuard)
{
char name[1024] = "";
struct Identifier * id = GetDeclId(func->declarator);

if(yylloc.start.included)
{
__ecereNameSpace__ecere__sys__PathCat(name, GetIncludeFileFromID((unsigned int)yylloc.start.included));
}
else if(sourceFile)
{
__ecereNameSpace__ecere__sys__PathCat(name, sourceFile);
}
__ecereNameSpace__ecere__sys__ChangeCh(name, '\\', '/');
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "{\n");
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "   __ecereNameSpace__ecere__com__MemoryGuard_PushLoc(\"%s:%s\");\n", name, id->string);
outputLine += 2;
}
OutputStatement(func->body, f);
if(inCompiler && memoryGuard)
{
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "   __ecereNameSpace__ecere__com__MemoryGuard_PopLoc();\n");
__ecereMethod___ecereNameSpace__ecere__sys__File_Printf(f, "}\n");
outputLine += 2;
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
}
curFunction = oldFunc;
}

static void OutputMemberInit(struct MemberInit * init, struct __ecereNameSpace__ecere__com__Instance * f)
{
if(init->identifiers)
{
if((*init->identifiers).count > 1)
{
struct Identifier * id;

for(id = (*init->identifiers).first; id; id = id->next)
{
OutputIdentifier(id, f);
if(id->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ".");
}
}
else if((*init->identifiers).first)
OutputIdentifier((*init->identifiers).first, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " = ");
}
if(init->initializer)
OutputInitializer(init->initializer, f);
}

static void OutputClassFunction(struct ClassFunction * func, struct __ecereNameSpace__ecere__com__Instance * f);

static void OutputMembersInit(struct MembersInit * init, struct __ecereNameSpace__ecere__com__Instance * f)
{
switch(init->type)
{
case 0:
{
struct MemberInit * member;

if(init->dataMembers)
{
for(member = (*init->dataMembers).first; member; member = member->next)
{
OutputMemberInit(member, f);
if(member->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
}
break;
}
case 1:
OutputClassFunction(init->function, f);
break;
}
}

static void OutputInstance(struct Instantiation * inst, struct __ecereNameSpace__ecere__com__Instance * f)
{
if(inst->_class)
OutputSpecifier(inst->_class, f);
if(inst->exp)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
OutputExpression(inst->exp, f);
}
if(inst->members && (*inst->members).count > 1)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n{\n");
outputLine += 2;
}
else if(inst->members)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " { ");
else
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "{");
if(inst->members)
{
struct MembersInit * init;

for(init = (*inst->members).first; init; init = init->next)
{
OutputMembersInit(init, f);
if(init->type == 0 && init->next)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ";\n");
outputLine++;
}
}
}
if(inst->members)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " }");
else
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "}");
}

static void OutputClassFunction(struct ClassFunction * func, struct __ecereNameSpace__ecere__com__Instance * f)
{
if(func->specifiers)
{
struct Specifier * spec;

for(spec = (*func->specifiers).first; spec; spec = spec->next)
{
OutputSpecifier(spec, f);
if(spec->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " ");
}
if(func->declarator)
OutputDeclarator(func->declarator, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
if(func->declarations)
{
struct Declaration * decl;

for(decl = (*func->declarations).first; decl; decl = decl->next)
{
OutputDeclaration(decl, f);
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
}
if(func->body)
{
OutputStatement(func->body, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
}
else
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ";");
}

static void OutputClassDef(struct ClassDef * def, struct __ecereNameSpace__ecere__com__Instance * f)
{
switch(def->type)
{
case 2:
if(def->decl)
{
OutputDeclaration(def->decl, f);
if(def->next && def->next->type != 2)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
}
}
break;
case 1:
{
struct MemberInit * init;

for(init = (*def->defProperties).first; init; init = init->next)
{
OutputMemberInit(init, f);
if(init->next)
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ", ");
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ";\n\n");
outputLine += 2;
break;
}
case 0:
OutputClassFunction(def->function, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
break;
}
}

static void OutputClass(struct ClassDefinition * _class, struct __ecereNameSpace__ecere__com__Instance * f)
{
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "class ");
OutputSpecifier(_class->_class, f);
if(_class->baseSpecs)
{
struct Specifier * spec;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, " : ");
for(spec = (*_class->baseSpecs).first; spec; spec = spec->next)
{
OutputSpecifier(spec, f);
}
}
if(_class->definitions)
{
struct ClassDef * def;

((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n{\n");
outputLine += 2;
for(def = (*_class->definitions).first; def; def = def->next)
{
OutputClassDef(def, f);
}
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "}\n");
outputLine++;
}
else
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, ";");
}

void OutputTree(struct __ecereNameSpace__ecere__sys__OldList * ast, struct __ecereNameSpace__ecere__com__Instance * f)
{
struct External * external;

outputLine = 11;
for(external = ast->first; external; external = external->next)
{
switch(external->type)
{
case 0:
OutputFunction(external->function, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
break;
case 1:
OutputDeclaration(external->declaration, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
break;
case 2:
OutputClass(external->_class, f);
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, const char *  string))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Puts])(f, "\n");
outputLine++;
break;
}
}
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__sys__TempFile;

struct __ecereNameSpace__ecere__sys__TempFile
{
char __ecere_padding[24];
};

extern char *  __ecereNameSpace__ecere__sys__TrimRSpaces(char *  string, char *  output);

extern void *  __ecereNameSpace__ecere__com__eInstance_New(struct __ecereNameSpace__ecere__com__Class * _class);

int __ecereVMethodID___ecereNameSpace__ecere__sys__File_GetSize;

int __ecereVMethodID___ecereNameSpace__ecere__sys__File_Seek;

int __ecereVMethodID___ecereNameSpace__ecere__sys__File_Read;

extern void __ecereNameSpace__ecere__com__eInstance_DecRef(struct __ecereNameSpace__ecere__com__Instance * instance);

char * StringFromSpecDecl(struct __ecereNameSpace__ecere__sys__OldList * specs, struct Declarator * decl)
{
char * string;
struct TypeName * typeName = __ecereNameSpace__ecere__com__eInstance_New(__ecereClass_TypeName);
struct __ecereNameSpace__ecere__com__Instance * f = __ecereNameSpace__ecere__com__eInstance_New(__ecereClass___ecereNameSpace__ecere__sys__TempFile);
unsigned int size;

typeName->qualifiers = specs;
typeName->declarator = decl;
OutputTypeName(typeName, f);
((typeName ? (__ecereClass_TypeName->Destructor ? __ecereClass_TypeName->Destructor(typeName) : 0, __ecereNameSpace__ecere__com__eSystem_Delete(typeName)) : 0), typeName = 0);
size = ((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_GetSize])(f);
string = __ecereNameSpace__ecere__com__eSystem_New(sizeof(char) * (size + 1));
((unsigned int (*)(struct __ecereNameSpace__ecere__com__Instance *, int pos, int mode))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Seek])(f, 0, 0);
((int (*)(struct __ecereNameSpace__ecere__com__Instance *, void *  buffer, unsigned int size, unsigned int count))f->_vTbl[__ecereVMethodID___ecereNameSpace__ecere__sys__File_Read])(f, string, 1, (unsigned int)size);
string[size] = '\0';
__ecereNameSpace__ecere__sys__TrimRSpaces(string, string);
(__ecereNameSpace__ecere__com__eInstance_DecRef(f), f = 0);
return string;
}

extern struct __ecereNameSpace__ecere__com__Class * __ecereClass___ecereNameSpace__ecere__com__GlobalFunction;

struct __ecereNameSpace__ecere__com__GlobalFunction;

extern struct __ecereNameSpace__ecere__com__GlobalFunction * __ecereNameSpace__ecere__com__eSystem_RegisterFunction(char *  name, char *  type, void *  func, struct __ecereNameSpace__ecere__com__Instance * module, int declMode);

void __ecereRegisterModule_output(struct __ecereNameSpace__ecere__com__Instance * module)
{
struct __ecereNameSpace__ecere__com__Class * class;

__ecereNameSpace__ecere__com__eSystem_RegisterFunction("SetMemoryGuard", "void SetMemoryGuard(bool b)", SetMemoryGuard, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("GetMemoryGuard", "bool GetMemoryGuard(void)", GetMemoryGuard, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("OutputTypeName", "void OutputTypeName(TypeName type, ecere::sys::File f)", OutputTypeName, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("OutputExpression", "void OutputExpression(Expression exp, ecere::sys::File f)", OutputExpression, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("OutputTree", "void OutputTree(ecere::sys::OldList ast, ecere::sys::File f)", OutputTree, module, 1);
__ecereNameSpace__ecere__com__eSystem_RegisterFunction("StringFromSpecDecl", "char * StringFromSpecDecl(ecere::sys::OldList specs, Declarator decl)", StringFromSpecDecl, module, 1);
}

void __ecereUnregisterModule_output(struct __ecereNameSpace__ecere__com__Instance * module)
{

}
