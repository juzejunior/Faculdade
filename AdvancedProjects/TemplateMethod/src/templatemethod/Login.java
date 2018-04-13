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
public abstract class Login {
    
    private String nome;
    private String senha;
    
    public abstract void notificaLogin();
    
    public boolean checkLogin(String nome, String senha) {
        if(nome.equals(this.nome) && senha.equals(this.senha)) {
            this.notificaLogin();
            return true;
        } 
        return false;
    } 

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }
    
    
}
