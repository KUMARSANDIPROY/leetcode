# Permutations of a given string
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor: pointer; background: 0% 0% no-repeat padding-box padding-box rgb(239, 248, 243); align-items: center; position: relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: rgb(51, 51, 51); --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:#142d23; --darkreader-inline-color:#c8c3bc;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: 0% 0% no-repeat padding-box padding-box transparent; opacity: 1; margin: 0px 16px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:transparent;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.</span></p>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input: </strong>ABC</span>
<strong><span style="font-size:18px">Output:</span></strong>
<span style="font-size:18px">ABC ACB BAC BCA CAB CBA</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">Given string ABC has permutations in 6 </span>
<span style="font-size:18px">forms as ABC, ACB, BAC, BCA, CAB and CBA .</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input: </strong>ABSG</span>
<strong><span style="font-size:18px">Output:</span></strong>
<span style="font-size:18px">ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
</span><span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">Given string ABSG has 24 permutations.</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>find_permutaion()&nbsp;</strong>which takes the string S as input parameter and returns a vector of string in lexicographical order.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(n! * n)</span></p>

<p><span style="font-size:18px"><strong>Expected Space&nbsp;Complexity:&nbsp;</strong>O(n)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= length of string &lt;= 5</span><br>
&nbsp;</p>

<p>&nbsp;</p>
 <p></p>
            </div>