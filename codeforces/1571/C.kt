//Hey stalker :)
import java.util.*
import kotlin.collections.ArrayList
import kotlin.reflect.typeOf

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun solve()
{
    var n = readInt()

    // var a = ArrayList<String>(n)// = arrayOfNulls(n)
    // var b = ArrayList<String>(n)// = arrayOfNulls(n)

    var x = 0
    var k_mi = 0
    var k_mx = 500004

    for(i in 0..n-1)
    {
        var (s, t, sr) = readStrings()
        
        var r = 0
        if(sr == "1")
            r = 1
        
        // a.add(s);
        // b.add(t);
        
        if(r == 1)
            x++

        if(r == 1)
        {
            var p = s.length
            var q = t.length
            var len = 0
            p--
            q--
            while(p >= 0 && q >= 0)
            {
                if(s[p] != t[q])
                {
                    break;
                }
                else
                {
                    len++
                    p--
                    q--
                }
            }
            if(len < k_mx)
            {
                k_mx = len
            }
        }
        else
        {
            var p = s.length
            var q = t.length
            var len = 0
            p--
            q--
            while(p >= 0 && q >= 0)
            {
                if(s[p] != t[q])
                {
                    break;
                }
                else
                {
                    len++
                    p--
                    q--
                }
            }
            if(len + 1 > k_mi)
            {
                k_mi = len + 1
            }
        }
    }
    // println("$x")
    // println("$k_mi - $k_mx")
    // println("")
    if(x != n)
    {
        if(k_mi == 0)
            k_mi++
    }
    
    if(k_mi > k_mx)
    {
        println("0")
        return
    }

    var op = k_mx - k_mi + 1
    println("$op")

    var pr = k_mi
    
    for(i in k_mi..k_mx)
    {
        print("$pr ")
        pr++
    }
    println()
}

fun main()
{
    // var t = 1
    var t = readInt()
    for (q in 1..t) 
    {
        solve()
    }
}
//   ©
//                      ______  __    __ ______ __    __ ________ ________ 
//                     /      \|  \  |  \      \  \  /  \        \        \
//                    |  ▓▓▓▓▓▓\ ▓▓\ | ▓▓\▓▓▓▓▓▓ ▓▓ /  ▓▓ ▓▓▓▓▓▓▓▓\▓▓▓▓▓▓▓▓
//  ______ ______     | ▓▓__| ▓▓ ▓▓▓\| ▓▓ | ▓▓ | ▓▓/  ▓▓| ▓▓__      | ▓▓   
// |      \      \    | ▓▓    ▓▓ ▓▓▓▓\ ▓▓ | ▓▓ | ▓▓  ▓▓ | ▓▓  \     | ▓▓   
//  \▓▓▓▓▓▓\▓▓▓▓▓▓    | ▓▓▓▓▓▓▓▓ ▓▓\▓▓ ▓▓ | ▓▓ | ▓▓▓▓▓\ | ▓▓▓▓▓     | ▓▓   
//                    | ▓▓  | ▓▓ ▓▓ \▓▓▓▓_| ▓▓_| ▓▓ \▓▓\| ▓▓_____   | ▓▓   
//                    | ▓▓  | ▓▓ ▓▓  \▓▓▓   ▓▓ \ ▓▓  \▓▓\ ▓▓     \  | ▓▓   
//  