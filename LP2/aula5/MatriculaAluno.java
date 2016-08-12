/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matriculaaluno;

/**
 *
 * @author aluno
 */
public class MatriculaAluno {

    private int totalMaterias;
    private int mAprovadas;
    private int matricula;

    
    public MatriculaAluno(int matricula, int totalMaterias){
        setMatricula(matricula);
        setTotalMaterias(totalMaterias);
        this.mAprovadas = 0;
    }
    /**
     * @return the totalMaterias
     */
    public int getTotalMaterias() {
        return totalMaterias;
    }

    /**
     * @param totalMaterias the totalMaterias to set
     */
    public void setTotalMaterias(int totalMaterias) {
        if(totalMaterias % 6 != 0 || totalMaterias == 0) System.out.println("O total de materias deve ser dividido por semestre em 6 materias");
        else this.totalMaterias = totalMaterias;
    }

    /**
     * @return the mAprovadas
     */
    public int getmAprovadas() {
        return mAprovadas;
    }

    /**
     * @param mAprovadas the mAprovadas to set
     */
    private void setmAprovadas(int mAprovadas) {
        if(this.mAprovadas + mAprovadas <= this.totalMaterias)
            this.mAprovadas += this.mAprovadas+mAprovadas;
        else System.out.println("Nao e possivel exceder o limite de materias!");
    }

    /**
     * @return the matricula
     */
    public int getMatricula() {
        return matricula;
    }

    /**
     * @param matricula the matricula to set
     */
    public void setMatricula(int matricula) {
        if(matricula < 0) System.out.println("A matricula nao pose ser negativa!");
        else this.matricula = matricula;
    }
    
    public int mateRestantes(){
        return this.totalMaterias - this.mAprovadas;
    }
    
    public int semestresRestantes(){
        int semestre = mateRestantes()/6;
        if(mateRestantes() % 6 != 0) semestre+=1;
           return semestre;
    }
    
    public void anosQueFaltam(){
        float ano = semestresRestantes() / 2;
        if(mateRestantes() == 0) System.out.println("Curso concluido!");
        else if(ano < 0) System.out.println("Restam 6 meses!");
        else if(semestresRestantes() % 2 != 0) System.out.println("Falta(m) "+(int)ano+" ano(s) e 6 meses!");
        else System.out.println("Falta(m) "+(int)ano+" anos.");
    }
    
    public void addSemestre(int passou){
        if(passou <= 6) setmAprovadas(passou);
        else System.out.println("Nao e possivel exceder o limite de materias");
    }
}
