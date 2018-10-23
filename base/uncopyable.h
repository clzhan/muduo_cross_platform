#ifndef MUDO_BASE_UNCOPYABLE_H_
#define MUDO_BASE_UNCOPYABLE_H_


#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);               \
    void operator=(const TypeName&)

#endif //MUDO_BASE_UNCOPYABLE_H_