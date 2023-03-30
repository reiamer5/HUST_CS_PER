import java.util.Scanner;
import java.util.TreeMap;
import java.util.Map;
/**
 * @author xiaodeng wust_dengshijun@163.com
 * @version 1.1 <br/>
 *          website:<a href="http://www.dengshijun.icoc.cc/">xiaodeng</a> <br>
 *          time:2015-02-25 Copyright (C),2012-2015,xiaodeng <br>
 *          This program is protected by xiaodeng
 *
 *	题目1149：子串计算
 *	时间限制：1 秒内存限制：32 兆特殊判题：否提交：918解决：512
 *	题目描述：
 *	给出一个01字符串（长度不超过100），求其每一个子串出现的次数。
 *	输入：
 *	输入包含多行，每行一个字符串。
 *	输出：
 *	对每个字符串，输出它所有出现次数在1次以上的子串和这个子串出现的次数，输出按字典序排序。
 *	样例输入：
 *	10101
 *	样例输出：
 *	0 2
 *	01 2
 *	1 3
 *	10 2
 *	101 2
 *	来源：
 *	2010年北京大学计算机研究生机试真题
 *	答疑：
 *	解题遇到问题?分享解题心得?讨论本题请访问：http://t.jobdu.com/thread-7872-1-1.html
 */

public class Main {

	private Map<String, Integer> subStr;

	public Main() {
		subStr = new TreeMap<String, Integer>();
	}

	public void countSubStr(String str) {
		String sub;
		subStr.clear();//很重要
		for (int i = 0; i < str.length(); i++) {
			for (int j = i + 1; j <= str.length(); j++) {
				sub = str.substring(i, j);
				if (subStr.get(sub) == null) {
					subStr.put(sub, 1);
				} else {
					subStr.put(sub, subStr.get(sub) + 1);
				}

			}
		}

		for (Map.Entry<String, Integer> e : subStr.entrySet()) {
			if (e.getValue() > 1) {
				System.out.println(e.getKey() + " " + e.getValue());
			}
		}

	}

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		Main ma = new Main();
		while (sc.hasNext()) {
			String str = sc.next();
			ma.countSubStr(str);
		}
	}

}
