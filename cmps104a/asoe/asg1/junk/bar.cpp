struct foo {
   int foo;
};
foo foo;
void bar () {
   foo.foo = 3;
}
//error: int bar;
