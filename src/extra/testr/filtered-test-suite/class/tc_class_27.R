expected <- eval(parse(text="structure(\"MethodDefinition\", package = \"methods\")"));        
test(id=0, code={        
argv <- eval(parse(text="list(structure(function (x, mode = \"any\") .Internal(as.vector(x, mode)), target = structure(\"ANY\", class = structure(\"signature\", package = \"methods\"), .Names = \"x\", package = \"methods\"), defined = structure(\"ANY\", class = structure(\"signature\", package = \"methods\"), .Names = \"x\", package = \"methods\"), generic = character(0), class = structure(\"MethodDefinition\", package = \"methods\")))"));        
do.call(`class`, argv);        
}, o=expected);        

