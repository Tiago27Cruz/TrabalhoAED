//
// Created by tomas on 30/10/2022.
//

#include "TurmaH.h"
#include <Algorithm>
/**
 * Construtor da classe TurmaH constituído por uma UC, a sua respetiva turma e o número de alunos inscritos
 * nessa UC nessa turma
 * @param codUC
 * @param codTurma
 */
TurmaH::TurmaH(std::string codUC, std::string codTurma) {
    this->codUC = codUC;
    this->codTurma = codTurma;
    nAlunos = 0;
}
/**
 * Retorna o código da UC
 * @return
 */
string TurmaH::getCodUc() const {
    return codUC;
}
/**
 * Retorna o código da turma
 */
string TurmaH::getCodTurma() const {
    return codTurma;
}
/**
 * Retorna o número de alunos presentemente inscritos nessa UC nessa turma
 * @return
 */
int TurmaH::getnAlunos() const {
    return nAlunos;
}
/**
 * Retorna um vetor com o horário de cada UC
 * @return
 */
vector<Slot> TurmaH::getHorario() const {
    return horario;
}
/**
 * Adiciona um slot de aulas ao horário
 * @param slot
 */
void TurmaH::addSlot(Slot slot) {
    horario.push_back(slot);
    std::sort(horario.begin(), horario.end());
}
void TurmaH::addAluno() {
    nAlunos++;
}
void TurmaH::removeAluno() {
    nAlunos -= 1;
}

void TurmaH::showHorario() {
    for(auto it: horario){
        int iniciomin=00;
        int finalmin=00;
        int inicioint=(int)(it.getHorarioInicio()*10);
        if (inicioint%10!=0){iniciomin=30;}
        inicioint/=10;
        int finalint=(int)(it.getHorarioFim()*10);
        if (finalint%10!=0){finalmin=30;}
        finalint/=10;
        string iniciomins,finalmins;
        if(iniciomin==0){iniciomins="00";}
        else{iniciomins= to_string(iniciomin);}
        if(finalmin==0){finalmins="00";}
        else{finalmins= to_string(finalmin);}
        cout << it.getDiaDaSemana() << " | " << inicioint <<":"<< iniciomins << " -> " << finalint <<":"<< finalmins << " | " << it.getTipo() << "\n";
    }
}

bool TurmaH::operator<(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma < s2.codTurma;
    }
    return codUC < s2.codUC;
}

bool TurmaH::operator>(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma > s2.codTurma;
    }
    return codUC > s2.codUC;
}

bool TurmaH::operator==(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma == s2.codTurma;
    }
    return codUC == s2.codUC;
}

bool TurmaH::operator!=(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma != s2.codTurma;
    }
    return codUC != s2.codUC;
}