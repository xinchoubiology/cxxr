expected <- eval(parse(text="c(2L, 1L, NA)"));      
test(id=0, code={      
argv <- eval(parse(text="list(c(2L, 1L, NA), FALSE, FALSE, NA)"));      
.Internal(`unique`(argv[[1]], argv[[2]], argv[[3]], argv[[4]]));      
}, o=expected);      

