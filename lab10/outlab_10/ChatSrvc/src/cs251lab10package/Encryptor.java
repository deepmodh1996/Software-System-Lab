package cs251lab10package;

import java.math.BigInteger;
import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.SecureRandom;
import java.security.spec.RSAPrivateKeySpec;
import java.security.spec.RSAPublicKeySpec;

import javax.crypto.Cipher;

public class Encryptor {
    static int keySize;
    static BigInteger modulus;
    static BigInteger publicExponent;
    static BigInteger privateExponent;
    static PublicKey pub;
    static PrivateKey priv;
    static PublicKey pub2;
    
    public void init(){
    	keySize = 1024;  
        SecureRandom random = new SecureRandom();
        // Choose two distinct prime numbers p and q.
        BigInteger p = BigInteger.probablePrime(keySize/2,random);
        BigInteger q = BigInteger.probablePrime(keySize/2,random);
        // Compute n = pq (modulus)
        modulus = p.multiply(q);
        // Compute φ(n) = φ(p)φ(q) = (p − 1)(q − 1) = n - (p + q -1), where φ is Euler's totient function.
        // and choose an integer e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1; i.e., e and φ(n) are coprime.
        BigInteger m = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));
        publicExponent = getCoprime(m,random);
        // Determine d as d ≡ e−1 (mod φ(n)); i.e., d is the multiplicative inverse of e (modulo φ(n)).
        privateExponent = publicExponent.modInverse(m);


        try {                    
            RSAPublicKeySpec spec = new RSAPublicKeySpec(modulus, publicExponent);
            RSAPrivateKeySpec privateSpec = new RSAPrivateKeySpec(modulus, privateExponent);

            KeyFactory factory = KeyFactory.getInstance("RSA");

            pub = factory.generatePublic(spec);
            priv = factory.generatePrivate(privateSpec); 

           // System.out.println("Public Key : "+ byteArrayToHexString( pub.getEncoded() ));
           // System.out.println("Private Key : "+ byteArrayToHexString( priv.getEncoded() ));
        }                        
        catch( Exception e ) {   
            System.out.println(e.toString());       
        }
    }
    
	public void setpub2(BigInteger mod,BigInteger exp){
		try{
		RSAPublicKeySpec spec = new RSAPublicKeySpec(mod,exp);
        KeyFactory factory = KeyFactory.getInstance("RSA");

        pub2 = factory.generatePublic(spec);
		}
		catch(Exception e){}
	}
    
	public static BigInteger getCoprime(BigInteger m, SecureRandom random) {
        int length = m.bitLength()-1;
        BigInteger e = BigInteger.probablePrime(length,random);
        while (! (m.gcd(e)).equals(BigInteger.ONE) ) {
            e = BigInteger.probablePrime(length,random);
        }
        return e;
    }

    public static String byteArrayToHexString(byte[] bytes){         
        StringBuffer buffer = new StringBuffer();
        for(int i=0; i<bytes.length; i++)
        {                        
            if(((int)bytes[i] & 0xff) < 0x10)       
                buffer.append("0");                               
            buffer.append(Long.toString((int) bytes[i] & 0xff, 16));
        }                        
        return buffer.toString();
    }         

    public static byte[] encrypt(String text) {
	    byte[] cipherText = null;
	    try {
	      // get an RSA cipher object and print the provider
	      final Cipher cipher = Cipher.getInstance("RSA");
	      // encrypt the plain text using the public key
	      cipher.init(Cipher.ENCRYPT_MODE, pub2);
	      cipherText = cipher.doFinal(text.getBytes());
	    } catch (Exception e) {
	      e.printStackTrace();
	    }
	    return cipherText;
     }
    
    public  String decrypt(byte[] text) {
	    byte[] dectyptedText = null;
	    try {
	      // get an RSA cipher object and print the provider
	      final Cipher cipher = Cipher.getInstance("RSA");

	      // decrypt the text using the private key
	      cipher.init(Cipher.DECRYPT_MODE, priv);
	      //System.out.println(privateExponent);
	      dectyptedText = cipher.doFinal(text);

	    } catch (Exception ex) {
	      ex.printStackTrace();
	    }

	    return new String(dectyptedText);
    }
}

