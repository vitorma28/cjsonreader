/*
Níveis de tokenização:

{"teste": 10}

1.: Separar por caracteres

Lista de caracteres normais.

{,",t,e,s,t,e,",:, ,1,0,}


2.: Separar por símbolos

SYMBOLS:

{ -> OPEN_MAP
} -> CLOSE_MAP

[ -> OPEN_ARR
] -> CLOSE_ARR

: -> ATTR_SEP
, -> PAIR_SEP
inner array:
    , -> VALUE_SEP

" -> OPEN/CLOSE _STR

0-9+ -> NUMBER

anything else -> TEXT



*/