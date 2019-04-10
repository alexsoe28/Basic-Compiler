struct foo {
   int foo;
};
struct foo foo;
void bar (void) {
   foo.foo = 3;
}
//error: int bar;
