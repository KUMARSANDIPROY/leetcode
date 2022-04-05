# Longest Repeating Subsequence
## Easy 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor: pointer; background: 0% 0% no-repeat padding-box padding-box rgb(239, 248, 243); align-items: center; position: relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: rgb(51, 51, 51); --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:#142d23; --darkreader-inline-color:#c8c3bc;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-color=""> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: 0% 0% no-repeat padding-box padding-box transparent; opacity: 1; margin: 0px 16px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor:transparent;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
str = "axxxy"
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The given array with indexes looks like
a x x x y 
0 1 2 3 4</span>

<span style="font-size:18px">The longest subsequence is "xx". 
It appears twice as explained below.</span>

<span style="font-size:18px"><strong>subsequence A</strong>
x x
0 1  &lt;-- index of subsequence A
------
1 2  &lt;-- index of str </span>

<span style="font-size:18px"><strong>
subsequence B</strong>
x x
0 1  &lt;-- index of subsequence B
------
2 3  &lt;-- index of str </span>

<span style="font-size:18px">We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
str = "aab"
<strong>Output:</strong> 1
<strong>Explanation: </strong>
The longest reapting subsequenece is "a".</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything. Your task is to complete the <strong>LongestRepeatingSubsequence()</strong> which takes str as input parameter and returns the length of the longest repeating subsequnece.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n<sup>2</sup>)<br>
<strong>Expected Space Complexity:</strong> O(n<sup>2</sup>)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= |str| &lt;= 10<sup>3</sup></span></p>
 <p></p>
            </div>