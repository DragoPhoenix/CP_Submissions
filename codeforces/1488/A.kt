private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

// 0 -> y
// =  0 + x * 10.p 

fun main(args: Array<String>) {
    var t = readInt()
    for (q in 0..t-1) {
        //var x : Long ;
        //var y: Long ;
        var (x, y) = readLongs()
        var k : Long  =0;
        var p : Long  = y;
        var d : Long  = 0;
        var c : Long  = 0;
        while(k!=y)
        {
        	//print("- $k $c -")
        	
        	if(k+x<=y && k+x*10>y)
        	{
        		//print("first\n")
        		var diff = (y-k)/x;
        		k+= (x*diff);
        		c+=diff;        
        	}
        	else if(k+x>y  && k+x*10>y)
        	{
        		//print("second\n")
        		c+=(y-k);
        		k=y;
        	}
        	else
        	{
        		//print("thord\n")
        		d=10;
        		while(k+x*d<=y)
        			d=d*10;
        		d/=10;
        		k+=x*d;
        		c++;
        	}
        }
        print("$c ")
        println()
    }
}