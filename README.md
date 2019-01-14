# Tautology_checker #
Introduction:a simple tautology checker in c(|,&,~)  
test data:  
&ensp;&ensp;&ensp;(1): (A|~A)&(B|~B)  
&ensp;&ensp;&ensp;(2): (A&~A)&C  
&ensp;&ensp;&ensp;(3): A|B|C|D|E|~A  
&ensp;&ensp;&ensp;(4): A&B&C&~B  
&ensp;&ensp;&ensp;(5): (A|B)&(A|~B)  
&ensp;&ensp;&ensp;(6): A&~B|~A&B  

results:  
&ensp;&ensp;&ensp;(1): True Forever  
&ensp;&ensp;&ensp;(2): False Forever  
&ensp;&ensp;&ensp;(3): True Forever  
&ensp;&ensp;&ensp;(4): False Forever  
&ensp;&ensp;&ensp;(5): Satisfactible  
&ensp;&ensp;&ensp;(6): Satisfactible  
