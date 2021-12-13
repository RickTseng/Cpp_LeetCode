#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        if(nums.size()==1){
            return 1;
        }
        int _max = -100001;
        int _min = 100001;
        int maxid = -1;
        int minid = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > _max)
            {
                _max = nums[i];
                maxid = i;
            }
            if (nums[i] < _min)
            {
                _min = nums[i];
                minid = i;
            }
        }
        int _step = 100001;
        _step = min(_step,max(n - maxid, n - minid));
        _step = min(_step,max(maxid + 1, minid + 1));
        _step = min(_step,(n - maxid) + (minid + 1));
        _step = min(_step,(maxid + 1) + (n - minid));
        return _step;
    }
};
int main()
{
    vector<int> nums = {33549,-71534,-69544,-68358,74579,-16325,-11458,25038,12657,79484,-50105,26409,75163,-69482,-30845,-83438,-86076,-35522,-20713,95629,46904,58841,-94046,32254,67237,34555,84161,-72605,-34630,88982,73406,-61922,86738,-23385,70824,58502,21609,55390,40938,60932,-11260,41514,77535,56466,-46130,18167,-66815,-86077,-97179,-69112,60241,87162,-46594,-29245,-19069,-17701,-70726,89899,58097,41525,82240,92555,27710,76905,79607,-91583,51795,-39100,81455,34538,34278,96620,-78191,44615,-23122,-67786,-96243,-63009,-68601,-72250,-8728,10000,-62625,-45355,23299,90088,72332,-19143,67021,-4604,-41325,40404,-49965,45966,31471,-13756,50400,81805,68399,44073,-93539,48944,16089,-41436,71829,-52464,-11676,9043,-48775,49036,-74748,4610,-82066,-7322,66382,88669,18870,63453,-48710,-60190,96896,34170,-87593,85315,89882,-11437,60555,-34367,15635,55782,-18262,-90982,-8141,9904,96198,-82139,68599,74555,48666,80098,-87121,98887,-56603,-23308,7337,16193,36647,-6590,-23697,-91398,31301,-65332,45944,-95386,-36567,86398,38782,-80156,13427,2353,-94327,-66478,32128,82502,-69678,-8223,84830,35164,78708,-56435,4397,-82069,-26755,-59422,47978,-54436,8252,-53561,33167,19329,-96668,-6234,43676,-56447,-33359,3787,81647,-91317,68455,75333,37189,-29496,8844,43058,86410,-38257,-62904,-19795,24465,-97250,-67365,50238,51953,-68539,38481,62923,-1832,-43615,35382,-53306,-95202,95451,68044,-20207,-26534,-52423,-24731,25838,7613,43500,25316,89332,77308,18702,-9918,7909,17314,-20880,12641,23651,3287,-53253,54514,-29821,36692,70785,91249,96404,74072,-87977,15214,71031,7182,-37003,-86536,35120,-28507,-55471,77221,2534,96753,-89602,-16461,-9883,-46550,36563,16023,-9767,73944,53445,1881,56760,2050,-32538,25343,-28680,39967,-59674,57413,524,93299,37560,22199,33782,83944,-12057,66749,-46296,-69621,68498,-62938,1941,27970,-80615,-9252,-78687,-39635,14250,17001,-87528,19338,75560,21409,-28981,-60418,84332,-11695,-8047,-2081,-66210,15667,-75124,-82679,-65721,60259,83596,-95552,-10086,63825,-34758,58055,-13630,68539,-13331,-44148,-76969,79148,78279,-22491,75635,60660,61563,-60020,74463,-21575,92684,-78502,-86578,85741,-15629,81414,50794,-64163,-71324,-44817,-15899,-56770,-49713,17384,-63638,51965,85478,9342,-84119,-5511,57295,-30096,-73354,-1596,53973,68996,-2344,-73480,-74007,32932,45664,53257,33971,-5840,16445,82023,-72311,25937,32160,-56187,31896,49837,-36654,72551,-51861,-14817,-23143,-86396,53030,19267,-30468,-54174,83597,98208,83553,-46089,15144,-57281,-96739,20060,-14950,25858,-20500,-46336,-83973,-62499,-14486,91438,-98955,-35700,-30299,-49275,-96113,-63287,55883,51517,11341,68870,50504,42509,-70510,68249,-42845,-71837,95924,56436,-26648,-97174,-14863,94342,-18949,90566,-88676,7346,-3749,91825,15532,37251,69007,-806,82205,-72182,56501,96095,-34134,-73812,35389,86737,-4384,-95144,30005,-4981,80433,4059,-91611,11176,-72730,-85775,28001,9053,-7629,37012,-37268,48345,73103,-65528,26944,-46482,5506,5010,-45998,75532,-17921,47548,-12369,-26551,15791,-24573,-5376,60863,-67306,-86432,-40519,-55131,46286,47513,-36924,-41898,-81763,-17309,8227,-45756,68981,-79590,-7713,82468,-91144,9146,12401,47132,-4665,58208,7247,30611,-97125,-92704,68465,61714,79188,3335,-72772,52860,18839,50687,-16484,91763,-61323,-43663,-38232,99841,68853,-64303,-26990,40977,7213,-18969,10346,8635,-6120,-42956,70270,-98117,-93236,-60184,-85627,78614,-12074,-53180,8163,-98485,67655,15145,60797,37303,63663,-5173,78748,-94737,-30901,2578,-20370,46093,22041,61867,72250,62208,-84351,-69669,69822,-74496,-85155,-18160,62325,-48435,35192,-31919,26469,67470,18186,-33049,-32031,50990,-52427,-14021,-67743,-30508,25828,35185,-90421,-16570,22004,39643,-80193,71610,96782,-51543,16478,-5977,10511,-10658,-87855,58750,17083,82801,67872,-8063,-26883,-47934,70081,-69807,15446,34471,3417,71861,-15386,-28204,-7043,-55224,-13710,73225,-70677,64052,-37118,-77112,-93571,-54609,10798,-91675,51485,55234,-1945,-40705,-93437,81291,4614,-44956,-41749,42275,67366,46419,2563,98508,68033,99402,66722,98335,10399,27353,25892,82175,20776,79933,72513,-11332,-32273,95805,94566,-66079,-44621,-15601,43989,-87530,61537,-75450,-38957,69709,38063,22325,93710,17324,-74932,-29028,81551,17088,28220,80307,48155,-2800,-12909,18192,41153,98527,17005,-6597,-20891,92714,-47984,-23104,29289,15679,-38571,-36179,-88356,49281,57907,-94283,-65744,-49167,-16998,-61281,-80568,-50917,92410,73095,-35686,-92834,-24099,36955,-12957,-52033,59305,-61343,-79848,21997,41507,55457,-10026,12650,-51008,14819,-66975,82877,-4696,-38903,26323,13220,-2818,40804,-5411,-11874,76262,-5297,-34791,-84930,-69419,-34133,77854,97305,-98713,21145,63636,-69709,-65607,16725,-71640,-37574,-31837,-71879,45338,69660,21180,20285,-13798,21675,8768,20328,36646,86927,-24580,78234,-66924,-26018,-11371,70388,-90833,-14203,-97995,76845,-72021,-9803,27786,-68022,-94132,-76713,28732,37015,98651,-29938,-87131,74539,-69585,21558,-76223,65716,-14449,-29117,-7054,74303,25772,21902,49365,-10576,-8774,47522,-95737,-90511,96756,67954,-91115,-77187,76225,-42447,-48131,-43349,-70176,48374,-80673,-36472,77142,-9765,31012,-24636,-62473,24579,85387,18339,-74138,78865,22411,-50290,31118,35236,29951,80968,-14636,4351,3482,-16801,-17284,20405,70347,-62040,-82407,77420,-95861,-16761,51769,57985,-31472,86987,54238,69180,-13038,33388,-91361,-4367,62794,47919,50491,-49970,48527,29962,73595,26139,-54613,28640,5698,72488,-18395,5980,-65200,62791,59722,-71270,65732,74048,-71471,91001,72850,-76112,48939,57192,12819,-26706,-44160,-53107,55936,-8029,-62748,-91354,-20801,-42664,23916,-24813,46324,-16495,42310,60662,58634,-46863,-15621,-3874,-60655,-54635,94460,99246,-64968,55352,-3883,-23762,67122,33185,-23693,39982,-84488,47771,-69069,-2572,-22820,58452,-57945,9777,-60040,-53249,-67012,81545,-75934,54906,-86490,-51286,-52070,66868,-28825,-18535,20797,-39070,-7368,88261,-90699,-55310,-3044,54899,2710,-58504,-29766,72639,56594,-37564,-11396,17800,2395,-87078,16905,2432,-35420,42543,-26800,-91179,23160,54204};
    Solution sol;
    int ans = sol.minimumDeletions(nums);
}

/*
[33549,-71534,-69544,-68358,74579,-16325,-11458,25038,12657,79484,-50105,26409,75163,-69482,-30845,-83438,-86076,-35522,-20713,95629,46904,58841,-94046,32254,67237,34555,84161,-72605,-34630,88982,73406,-61922,86738,-23385,70824,58502,21609,55390,40938,60932,-11260,41514,77535,56466,-46130,18167,-66815,-86077,-97179,-69112,60241,87162,-46594,-29245,-19069,-17701,-70726,89899,58097,41525,82240,92555,27710,76905,79607,-91583,51795,-39100,81455,34538,34278,96620,-78191,44615,-23122,-67786,-96243,-63009,-68601,-72250,-8728,10000,-62625,-45355,23299,90088,72332,-19143,67021,-4604,-41325,40404,-49965,45966,31471,-13756,50400,81805,68399,44073,-93539,48944,16089,-41436,71829,-52464,-11676,9043,-48775,49036,-74748,4610,-82066,-7322,66382,88669,18870,63453,-48710,-60190,96896,34170,-87593,85315,89882,-11437,60555,-34367,15635,55782,-18262,-90982,-8141,9904,96198,-82139,68599,74555,48666,80098,-87121,98887,-56603,-23308,7337,16193,36647,-6590,-23697,-91398,31301,-65332,45944,-95386,-36567,86398,38782,-80156,13427,2353,-94327,-66478,32128,82502,-69678,-8223,84830,35164,78708,-56435,4397,-82069,-26755,-59422,47978,-54436,8252,-53561,33167,19329,-96668,-6234,43676,-56447,-33359,3787,81647,-91317,68455,75333,37189,-29496,8844,43058,86410,-38257,-62904,-19795,24465,-97250,-67365,50238,51953,-68539,38481,62923,-1832,-43615,35382,-53306,-95202,95451,68044,-20207,-26534,-52423,-24731,25838,7613,43500,25316,89332,77308,18702,-9918,7909,17314,-20880,12641,23651,3287,-53253,54514,-29821,36692,70785,91249,96404,74072,-87977,15214,71031,7182,-37003,-86536,35120,-28507,-55471,77221,2534,96753,-89602,-16461,-9883,-46550,36563,16023,-9767,73944,53445,1881,56760,2050,-32538,25343,-28680,39967,-59674,57413,524,93299,37560,22199,33782,83944,-12057,66749,-46296,-69621,68498,-62938,1941,27970,-80615,-9252,-78687,-39635,14250,17001,-87528,19338,75560,21409,-28981,-60418,84332,-11695,-8047,-2081,-66210,15667,-75124,-82679,-65721,60259,83596,-95552,-10086,63825,-34758,58055,-13630,68539,-13331,-44148,-76969,79148,78279,-22491,75635,60660,61563,-60020,74463,-21575,92684,-78502,-86578,85741,-15629,81414,50794,-64163,-71324,-44817,-15899,-56770,-49713,17384,-63638,51965,85478,9342,-84119,-5511,57295,-30096,-73354,-1596,53973,68996,-2344,-73480,-74007,32932,45664,53257,33971,-5840,16445,82023,-72311,25937,32160,-56187,31896,49837,-36654,72551,-51861,-14817,-23143,-86396,53030,19267,-30468,-54174,83597,98208,83553,-46089,15144,-57281,-96739,20060,-14950,25858,-20500,-46336,-83973,-62499,-14486,91438,-98955,-35700,-30299,-49275,-96113,-63287,55883,51517,11341,68870,50504,42509,-70510,68249,-42845,-71837,95924,56436,-26648,-97174,-14863,94342,-18949,90566,-88676,7346,-3749,91825,15532,37251,69007,-806,82205,-72182,56501,96095,-34134,-73812,35389,86737,-4384,-95144,30005,-4981,80433,4059,-91611,11176,-72730,-85775,28001,9053,-7629,37012,-37268,48345,73103,-65528,26944,-46482,5506,5010,-45998,75532,-17921,47548,-12369,-26551,15791,-24573,-5376,60863,-67306,-86432,-40519,-55131,46286,47513,-36924,-41898,-81763,-17309,8227,-45756,68981,-79590,-7713,82468,-91144,9146,12401,47132,-4665,58208,7247,30611,-97125,-92704,68465,61714,79188,3335,-72772,52860,18839,50687,-16484,91763,-61323,-43663,-38232,99841,68853,-64303,-26990,40977,7213,-18969,10346,8635,-6120,-42956,70270,-98117,-93236,-60184,-85627,78614,-12074,-53180,8163,-98485,67655,15145,60797,37303,63663,-5173,78748,-94737,-30901,2578,-20370,46093,22041,61867,72250,62208,-84351,-69669,69822,-74496,-85155,-18160,62325,-48435,35192,-31919,26469,67470,18186,-33049,-32031,50990,-52427,-14021,-67743,-30508,25828,35185,-90421,-16570,22004,39643,-80193,71610,96782,-51543,16478,-5977,10511,-10658,-87855,58750,17083,82801,67872,-8063,-26883,-47934,70081,-69807,15446,34471,3417,71861,-15386,-28204,-7043,-55224,-13710,73225,-70677,64052,-37118,-77112,-93571,-54609,10798,-91675,51485,55234,-1945,-40705,-93437,81291,4614,-44956,-41749,42275,67366,46419,2563,98508,68033,99402,66722,98335,10399,27353,25892,82175,20776,79933,72513,-11332,-32273,95805,94566,-66079,-44621,-15601,43989,-87530,61537,-75450,-38957,69709,38063,22325,93710,17324,-74932,-29028,81551,17088,28220,80307,48155,-2800,-12909,18192,41153,98527,17005,-6597,-20891,92714,-47984,-23104,29289,15679,-38571,-36179,-88356,49281,57907,-94283,-65744,-49167,-16998,-61281,-80568,-50917,92410,73095,-35686,-92834,-24099,36955,-12957,-52033,59305,-61343,-79848,21997,41507,55457,-10026,12650,-51008,14819,-66975,82877,-4696,-38903,26323,13220,-2818,40804,-5411,-11874,76262,-5297,-34791,-84930,-69419,-34133,77854,97305,-98713,21145,63636,-69709,-65607,16725,-71640,-37574,-31837,-71879,45338,69660,21180,20285,-13798,21675,8768,20328,36646,86927,-24580,78234,-66924,-26018,-11371,70388,-90833,-14203,-97995,76845,-72021,-9803,27786,-68022,-94132,-76713,28732,37015,98651,-29938,-87131,74539,-69585,21558,-76223,65716,-14449,-29117,-7054,74303,25772,21902,49365,-10576,-8774,47522,-95737,-90511,96756,67954,-91115,-77187,76225,-42447,-48131,-43349,-70176,48374,-80673,-36472,77142,-9765,31012,-24636,-62473,24579,85387,18339,-74138,78865,22411,-50290,31118,35236,29951,80968,-14636,4351,3482,-16801,-17284,20405,70347,-62040,-82407,77420,-95861,-16761,51769,57985,-31472,86987,54238,69180,-13038,33388,-91361,-4367,62794,47919,50491,-49970,48527,29962,73595,26139,-54613,28640,5698,72488,-18395,5980,-65200,62791,59722,-71270,65732,74048,-71471,91001,72850,-76112,48939,57192,12819,-26706,-44160,-53107,55936,-8029,-62748,-91354,-20801,-42664,23916,-24813,46324,-16495,42310,60662,58634,-46863,-15621,-3874,-60655,-54635,94460,99246,-64968,55352,-3883,-23762,67122,33185,-23693,39982,-84488,47771,-69069,-2572,-22820,58452,-57945,9777,-60040,-53249,-67012,81545,-75934,54906,-86490,-51286,-52070,66868,-28825,-18535,20797,-39070,-7368,88261,-90699,-55310,-3044,54899,2710,-58504,-29766,72639,56594,-37564,-11396,17800,2395,-87078,16905,2432,-35420,42543,-26800,-91179,23160,54204]
505

Runtime: 160 ms, faster than 62.82% of C++ online submissions for Removing Minimum and Maximum From Array.
Memory Usage: 88.3 MB, less than 69.48% of C++ online submissions for Removing Minimum and Maximum From Array.
Constraints:

1 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5
The integers in nums are distinct.

*/