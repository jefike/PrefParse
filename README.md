# PrefParse

Parses preference expressions of the type "condition | option1 > option2" where the options are members of the same category and outputs the transitive closure of the differs-by-one matrix.

Categories are protein, optional plate, side, and starter.
Options are chicken or shrimp, dessert or appetizer, potatoes or pasta, and soup or salad.

A conditon may be one or more options or the keyword "anything."

Examples:

anything | chicken > shrimp

chicken | dessert > appetizer

dessert and chicken | potatoes < pasta


Compile with make. Use make debug to output differs-by-one matrix as well.
