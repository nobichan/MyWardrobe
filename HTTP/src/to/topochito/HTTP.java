package to.topochito;

import java.net.*;
import java.io.*;
import java.util.*;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;

class MyProxySelector extends ProxySelector {
	public List<Proxy> select(URI uri) {
		String proxyHost = null;
		proxyHost = "10.101.0.1";
		if (proxyHost != null)
			return Arrays.asList(new Proxy(Proxy.Type.HTTP,
					new InetSocketAddress(proxyHost, 8080)));
		else
			return Arrays.asList(Proxy.NO_PROXY);
	}
	// Proxyへの接続に失敗すると呼ばれるメソッド
	public void connectFailed(URI uri, SocketAddress sa, IOException ioe) {
		ioe.printStackTrace();
	}
}

class XMLReader {
	private static String xmlFile = "HTTP.xml";
	public static void main(String[] args) throws Exception {
		if (args.length < 1) {
			System.err.println("Usage: 引数1 xmlファイル");
			System.exit(-1);
		}
		xmlFile = args[0];
		parseXml(xmlFile);
	}
	private static void parseXml(String xmlFile) throws Exception {
		DocumentBuilderFactory dbf
				= DocumentBuilderFactory.newInstance();
		DocumentBuilder db
				= dbf.newDocumentBuilder();

		Document doc = db.parse(new FileInputStream(xmlFile));;

		Element root =doc.getDocumentElement();

		walk(root);

	}
	private static void walk(Node node) {
		for (Node ch = node.getFirstChild();	//指定されたノードの最初の子を取得して
			 ch != null;						//子がいる限り
			 ch = ch.getNextSibling()) {		//兄弟をたどる
			System.out.println(ch.getNodeName());
		}
	}

}

public class HTTP {

	public static void main(String[] args) throws Exception {
	// write your code here
//        ProxySelector.setDefault(new MyProxySelector());
		URL url = new URL("http://www.yahoo.co.jp/");
		URLConnection uc = url.openConnection();
		uc.connect();
		BufferedReader in = new BufferedReader(
				new InputStreamReader(
						uc.getInputStream()));
		String inputLine;
		while ((inputLine = in.readLine()) != null)
			System.out.println(inputLine);
		in.close();
	}
}
