/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:20:00 by beyarsla          #+#    #+#             */
/*   Updated: 2024/08/09 19:12:31 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	ft_print(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->t_data->time_to_sleep);
}

void	odd_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->time_of_last_meal = get_current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	ft_print(philo, "is eating");
	ft_usleep(philo->t_data->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	even_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->time_of_last_meal = get_current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	ft_print(philo, "is eating");
	ft_usleep(philo->t_data->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
