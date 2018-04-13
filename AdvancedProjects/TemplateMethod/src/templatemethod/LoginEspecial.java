/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package templatemethod;

/**
 *
 * @author jose
 */
public class LoginEspecial extends Login {

    @Override
    public void notificaLogin() {
        System.out.println("Logado com sucesso!");
    }
    
    public static void main(String[] args) {
        Login login = new LoginEspecial();
        login.setNome("alberto");
        login.setSenha("123");
        login.checkLogin("alberto", "123");
    }

}
