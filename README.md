# PrefParse

Parses preference expressions of the type "condition | option1 > option2" where the options are members of the same category and outputs the transitive closure of the differs-by-one matrix.

This transitive closure matrix shows the most preferred meals. The matrix is read such that
"Y is preferred to X" if there is a 1 in the x,y coordinate. Position 0 is at the top left.

Categories are protein, optional plate, side, and starter.
Options are chicken or shrimp, dessert or appetizer, potatoes or pasta, and soup or salad.

A conditon may be one or more options or the keyword "anything."

Examples:

anything | chicken > shrimp

chicken | dessert > appetizer

dessert and chicken | potatoes < pasta


Compile with make. Use make debug to output differs-by-one matrix as well.
