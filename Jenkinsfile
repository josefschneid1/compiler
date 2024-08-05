pipeline {
    agent any

    stages {

        stage('Build Image') {
            sh 'docker build . -t image'
        }
        stage('Build Application') {
            sh 'docker run -v .:/src image sh -c "conan build ."'
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        } 
    }
}