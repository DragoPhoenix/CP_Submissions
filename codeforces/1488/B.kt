private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    for (q in 0..t-1) {
        var (n, k) = readInts()
        var s = readLn()
        var d = 0;
        var f = 0;
        var c = 0;
        var i = 0;
        while(i < n)
        {
            //println("$s ")
        	if(s[i]=='(')
        		d++;
        	else
        	{
        		d--;
        		// if(i>0&&s[i-1]=='('&&d>=1&&k!=0)
        		// {
        		//     var s1 = s.substring(0,i-1);
        		//     var s2="";
        		//     if(i+1<=s.length-1)
        		//         s2 = s.substring(i+1,s.length);
        		//         //println("$s1 & $s2")
        		//     s= s1 + s2;
        		// 	i=i-2;
        		// 	c++;
        		// 	k--;
        		// }
        		f++;
        	}
        	if(d==0)
        	{
        		c++;
        	}
        	i++;
        }
        if(f-c<=k)
        c+=(f-c);
        else
        c+=k;
        print("$c ")
        println()
    }
}